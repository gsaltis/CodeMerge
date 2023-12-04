/*****************************************************************************
 * FILE NAME    : SourceTree.cpp
 * DATE         : December 02 2023
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
#include "SourceTree.h"
#include "main.h"
#include "StringTuple.h"
#include "SourceTreeItem.h"

/*****************************************************************************!
 * Function : SourceTree
 *****************************************************************************/
SourceTree::SourceTree
() : QTreeWidget()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~SourceTree
 *****************************************************************************/
SourceTree::~SourceTree
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
SourceTree::initialize()
{
  CreateConnections();
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
SourceTree::resizeEvent
(QResizeEvent* InEvent)
{
  QSize					size;  
  int					width;
  int					height;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  (void)height;
  (void)width;
}

/*****************************************************************************!
 * Function : AddModuleSet
 *****************************************************************************/
void
SourceTree::AddModuleSet
(BuildModuleSet* InModuleSet1, BuildModuleSet* InModuleSet2)
{
  QTreeWidgetItem*                      track3Items;
  QTreeWidgetItem*                      track2Items;
  QTreeWidgetItem*                      commonItems;
  QString                               source2TrackPath;
  QString                               source1TrackPath;
  SourceTreeItem*                       treeItem;
  QString                               s1;
  bool                                  found;
  int                                   i;
  int                                   n;
  QList<StringTuple*>                   sources;
  StringTuple*                          st;
  QString                               s2;
  QString                               modName;
  QString                               name;
  QList<BuildSource*>                   sources1;
  QList<BuildSource*>                   sources2;
  QTreeWidgetItem*                      header;

  ModuleSet1 = InModuleSet1;
  ModuleSet2 = InModuleSet2;
  
  header = new QTreeWidgetItem();
  header->setFont(0, MainSystemSettings->GetTreeHeaderFont());
  header->setText(0, "Source Files");
  setHeaderItem(header);

  sources1 = InModuleSet1->GetAllBuildSources();
  sources2 = InModuleSet2->GetAllBuildSources();
  source1TrackPath = InModuleSet1->GetTrackPath();
  source2TrackPath = InModuleSet2->GetTrackPath();

  //!  
  for ( auto i2 : sources1 ) {
    name = i2->GetSourceName();
    modName = i2->GetModuleName();
    s2 = BuildSource::NormalizeFilename(name, modName, source1TrackPath);
    n = sources.size();
    found = false;
    for (i = 0; i < n; i++) {
      st = sources[i];
      if ( st->GetString1() == s2 ) {
        found = true;
        break;
      }
    }
    if ( found ) {
      continue;
    }
    st = new StringTuple(s2, QString());
    sources << st;
  }

  for ( auto i2 : sources2 ) {
    name = i2->GetSourceName();
    modName = i2->GetModuleName();
    s2 = BuildSource::NormalizeFilename(name, modName, source2TrackPath);
    n = sources.size();
    found = false;
    for (i = 0; i < n; i++) {
      st = sources[i];
      if ( st->GetString1() == s2 ) {
        found = true;
        break;
      }
    }
    if ( found ) {
      st->SetString2(s2);
      continue;
    }
    st = new StringTuple(QString(), s2);
    sources << st;
  }

  std::sort(sources.begin(), sources.end(),
            [](StringTuple* InSt1, StringTuple* InSt2) {
              return InSt2->Compare(InSt1) < 0;
            });

  commonItems = new QTreeWidgetItem();
  commonItems->setText(0, "Common");
  addTopLevelItem(commonItems);

  track2Items = NULL;
  track3Items = NULL;

  //!
  for ( auto st3 : sources ) {
    s1 = st3->GetString1();
    s2 = st3->GetString2();
    if ( s1 == s2 ) {
      treeItem = new SourceTreeItem(s1);
      connect(treeItem,
              SourceTreeItem::SignalFilesSelected,
              this,
              SourceTree::SlotFilesSelected);
      treeItem->SetModuleSet1(InModuleSet1);
      treeItem->SetModuleSet2(InModuleSet2);
      commonItems->addChild(treeItem);
      continue;
    }
    if ( s1.isEmpty() ) {
      treeItem = new SourceTreeItem(s2);
      connect(treeItem,
              SourceTreeItem::SignalFilesSelected,
              this,
              SourceTree::SlotFilesSelected);
      if ( track3Items == NULL ) {
        track3Items = new QTreeWidgetItem();
        track3Items->setText(0, "Track3 Only");
        treeItem->SetModuleSet2(InModuleSet2);
        addTopLevelItem(track3Items);
      }
      track3Items->addChild(treeItem);
      continue;
    }
    if ( track2Items == NULL ) {
      track2Items = new QTreeWidgetItem();
      track2Items->setText(0, "Track2 Only");
      addTopLevelItem(track2Items);
    }
    treeItem = new SourceTreeItem(s1);
    connect(treeItem,
            SourceTreeItem::SignalFilesSelected,
            this,
            SourceTree::SlotFilesSelected);
    track2Items->addChild(treeItem);
    treeItem->SetModuleSet1(InModuleSet1);
  }
  commonItems->setExpanded(true);
}

/*****************************************************************************!
 * Function : SlotItemSelected
 *****************************************************************************/
void
SourceTree::SlotItemSelected
(QTreeWidgetItem* InItem)
{
  QString                               text;
  SourceTreeItem*                       item;

  item = (SourceTreeItem*)InItem;
  item->ProcessSelected();
  text = item->GetText();
}

/*****************************************************************************!
 * Function : CreateConnections
 *****************************************************************************/
void
SourceTree::CreateConnections(void)
{
  connect(this,
          QTreeWidget::itemClicked,
          this,
          SourceTree::SlotItemSelected);
}

/*****************************************************************************!
 * Function : SlotFilesSelected
 *****************************************************************************/
void
SourceTree::SlotFilesSelected
(QString InFileName1, QString InASTPath1, QString InLocalIncludeDir1, QString InFileName2, QString InASTPath2, QString InLocalIncludeDir2)
{
  int                                   returnCode;
  QString                               args1;
  QString                               args2;
  QString                               clangArgs;
  QString                               stdIncludeDir;
  QString                               localIncludeDir;
  QString                               errors;
  QString                               output;
  
  clangArgs = MainSystemSettings->GetClangArgs();
  stdIncludeDir = MainSystemSettings->GetClangStdIncludeDir();

  if ( ModuleSet1 ) {
    args1 = QString(clangArgs).arg(InASTPath1).arg(stdIncludeDir).arg(InLocalIncludeDir1).arg(InFileName1);
    ExecuteSetup(ModuleSet1);
    returnCode = Execute(errors, output, args1, ModuleSet1);
    if ( returnCode == 0 ) {
      ProcessCompile(ModuleSet1->GetTrackName(), InASTPath1, InFileName1, errors, output);
    } else {      
      ProcessError(errors);
    }
  }
  if ( ModuleSet2 ) {
    args2 = QString(clangArgs).arg(InASTPath2).arg(stdIncludeDir).arg(InLocalIncludeDir2).arg(InFileName2);
    ExecuteSetup(ModuleSet2);
    returnCode = Execute(errors, output, args2, ModuleSet2);
    if ( returnCode == 0 ) {
      ProcessCompile(ModuleSet2->GetTrackName(), InASTPath2, InFileName2, errors, output);
    } else {      
      ProcessError(errors);
    }
  }
}

/*****************************************************************************!
 * Function : Execute
 *****************************************************************************/
int
SourceTree::Execute
(QString &InErrors, QString &InOutput, QString InArgs, BuildModuleSet* InModuleSet)
{
  QProcess                              makeProcess;
  QString                               clangPath;
  QString                               fullPath;
  
  clangPath = MainSystemSettings->GetClangPath();
  fullPath = InModuleSet->GetTrackPath();
  makeProcess.setArguments(InArgs.split(QRegularExpression("\\s+")));
  makeProcess.setProgram(clangPath);
  makeProcess.setWorkingDirectory(fullPath);
  makeProcess.start();
  makeProcess.waitForFinished();
  InErrors = QString(makeProcess.readAllStandardError());
  InOutput = QString(makeProcess.readAllStandardOutput());
  return makeProcess.exitCode();
}

/*****************************************************************************!
 * Function : ExecuteSetup
 *****************************************************************************/
void
SourceTree::ExecuteSetup
(BuildModuleSet* InModuleSet)
{
  QString                               envString;
  QString                               fullPath;
  
  fullPath = InModuleSet->GetTrackPath();
  envString = QString("ACU_SOURCE_DIR=") + fullPath;
  putenv(envString.toStdString().c_str());
}

/*****************************************************************************!
 * Function : ProcessOutput
 *****************************************************************************/
void
SourceTree::ProcessOutput
(QString )
{
}

/*****************************************************************************!
 * Function : ProcessError
 *****************************************************************************/
void
SourceTree::ProcessError
(QString InError)
{
  emit SignalErrorMessage(InError);
}

/*****************************************************************************!
 * Function : ProcessCompile
 *****************************************************************************/
void
SourceTree::ProcessCompile
(QString InTrackName, QString InASTPath, QString InFileName, QString InErrors, QString InOutput)
{
  emit SignalCompileSuccess(InTrackName, InASTPath, InFileName, InErrors, InOutput);
}
