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
(QString InText) : QTreeWidgetItem()
{
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
  moduleSet1 = InModuleSet1;  
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
  moduleSet2 = InModuleSet2;  
}

/*****************************************************************************!
 * Function : ProcessSelected
 *****************************************************************************/
void
SourceTreeItem::ProcessSelected(void)
{
  bool                                  exists;
  QFileInfo                             fileInfo;
  QString                               path;
  QString                               fullPath;
  if ( moduleSet1 ) {
    path = moduleSet1->GetTrackPath();
    fullPath = path + "/" + text;
    fileInfo.setFile(fullPath);
    exists = fileInfo.exists();
    TRACE_FUNCTION_QSTRING(fullPath);
    TRACE_FUNCTION_BOOL(exists);
  }

  if ( moduleSet2 ) {
    path = moduleSet2->GetTrackPath();
    fullPath = path + "/" + text;
    fileInfo.setFile(fullPath);
    exists = fileInfo.exists();
    TRACE_FUNCTION_QSTRING(fullPath);
    TRACE_FUNCTION_BOOL(exists);
  }
}
