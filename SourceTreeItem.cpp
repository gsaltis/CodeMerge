/*****************************************************************************
 * FILE NAME    : SourceTreeItem.cpp
 * DATE         : December 03 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <trace_winnetqt.h>
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "SourceTreeItem.h"

/*****************************************************************************!
 * Function : SourceTreeItem
 *****************************************************************************/
SourceTreeItem::SourceTreeItem
(QString InText) : QWidget(), QTreeWidgetItem()
{
  ASTCreatedColor = QColor(128, 0, 0);
  ASTCreatedFont = QFont("Segoe UI", 10, QFont::Bold);
  initialize();
  text = InText;
  setText(0, text);
}

/*****************************************************************************!
 * Function : ~SourceTreeItem
 *****************************************************************************/
SourceTreeItem::~SourceTreeItem
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
SourceTreeItem::initialize()
{
  moduleSet1 = NULL;
  moduleSet2 = NULL;
}

/*****************************************************************************!
 * Function : GetText
 *****************************************************************************/
QString
SourceTreeItem::GetText
()
{
  return text;
}

/*****************************************************************************!
 * Function : SetText
 *****************************************************************************/
void
SourceTreeItem::SetText
(QString InText)
{
  setText(0, InText);
  text = InText;
}

/*****************************************************************************!
 * Function : GetModuleSet1
 *****************************************************************************/
BuildModuleSet*
SourceTreeItem::GetModuleSet1(void)
{
  return moduleSet1;  
}

/*****************************************************************************!
 * Function : SetModuleSet1
 *****************************************************************************/
void
SourceTreeItem::SetModuleSet1
(BuildModuleSet* InModuleSet1)
{
  QString                       trackName1;

  trackName1 = InModuleSet1->GetTrackName();
  moduleSet1 = InModuleSet1;  
  CheckASTPath(moduleSet1);
}

/*****************************************************************************!
 * Function : GetModuleSet2
 *****************************************************************************/
BuildModuleSet*
SourceTreeItem::GetModuleSet2(void)
{
  return moduleSet2;  
}

/*****************************************************************************!
 * Function : SetModuleSet2
 *****************************************************************************/
void
SourceTreeItem::SetModuleSet2
(BuildModuleSet* InModuleSet2)
{
  QString                       trackName2;

  trackName2 = InModuleSet2->GetTrackName();
  moduleSet2 = InModuleSet2;
  CheckASTPath(moduleSet2);
}

/*****************************************************************************!
 * Function : ProcessSelected
 *****************************************************************************/
void
SourceTreeItem::ProcessSelected(void)
{
  QString                               includeDir1;
  QString                               includeDir2;
  QString                               astPath1;
  QString                               astPath2;
  QString                               baseName;
  QString                               filePath;
  QString                               path;
  QString                               fullPath1;
  QString                               fullPath2;
  QFileInfo                             info;
  
  if ( moduleSet1 ) {
    path = moduleSet1->GetTrackPath();
    fullPath1 = path + text;

    info.setFile(text);
    filePath = info.path();
    baseName = info.completeBaseName();
    astPath1 = moduleSet1->GetASTPath() + filePath.replace(QChar('/'), QChar('-')) + "-" + baseName + ".ast";
    includeDir1 = path + "include";
  }

  if ( moduleSet2 ) {
    path = moduleSet2->GetTrackPath();
    fullPath2 = path + text;

    info.setFile(text);
    filePath = info.path();
    baseName = info.completeBaseName();
    astPath2 = moduleSet2->GetASTPath() + filePath.replace(QChar('/'), QChar('-')) + "-" + baseName + ".ast";
    includeDir2 = path + "include";
  }

  emit SignalFilesSelected(fullPath1, astPath1, includeDir1, fullPath2, astPath2, includeDir2);
}

/*****************************************************************************!
 * Function : CheckASTPath
 *****************************************************************************/
void
SourceTreeItem::CheckASTPath
(BuildModuleSet* InModuleSet)
{
  QFileInfo                             fileInfo;
  QString                               astPath;

  astPath = GetASTPath(InModuleSet);
  fileInfo.setFile(astPath);
  if ( fileInfo.exists() ) {
    setForeground(0, QBrush(ASTCreatedColor));
    QTreeWidgetItem::setFont(0, ASTCreatedFont);
  }
}

/*****************************************************************************!
 * Function : GetASTPath
 *****************************************************************************/
QString
SourceTreeItem::GetASTPath
(BuildModuleSet* InModuleSet)
{
  QFileInfo                             info;
  QString                               astPath;
  QString                               baseName;
  QString                               filePath;
  QString                               fullPath1;
  QString                               path;

  path = InModuleSet->GetTrackPath();
  fullPath1 = path + text;

  info.setFile(text);
  filePath = info.path();
  baseName = info.completeBaseName();
  astPath = InModuleSet->GetASTPath() + filePath.replace(QChar('/'), QChar('-')) + "-" + baseName + ".ast";
  return astPath;
}
