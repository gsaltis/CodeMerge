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
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
SourceTree::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
SourceTree::InitializeSubWindows()
{
  
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
  QTreeWidgetItem*                      treeItem;
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

  header = new QTreeWidgetItem();
  header->setFont(0, MainSystemSettings->GetTreeHeaderFont());
  header->setText(0, "Source Files");
  setHeaderItem(header);

  sources1 = InModuleSet1->GetAllBuildSources();
  sources2 = InModuleSet2->GetAllBuildSources();
  source1TrackPath = InModuleSet1->GetTrackPath();
  source2TrackPath = InModuleSet2->GetTrackPath();
  
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
  
  for ( auto st3 : sources ) {
    s1 = st3->GetString1();
    s2 = st3->GetString2();
    if ( s1 == s2 ) {
      treeItem = new QTreeWidgetItem();
      treeItem->setText(0, s1);
      commonItems->addChild(treeItem);
      continue;
    }
    if ( s1.isEmpty() ) {
      treeItem = new QTreeWidgetItem();
      treeItem->setText(0, s2);
      if ( track3Items == NULL ) {
        track3Items = new QTreeWidgetItem();
        track3Items->setText(0, "Track3 Only");
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
    treeItem = new QTreeWidgetItem();
    treeItem->setText(0, s1);
    track2Items->addChild(treeItem);
  }
}

/*****************************************************************************!
 * Function : GetSourceName
 *****************************************************************************/
QString
SourceTree::GetSourceName
(QString InName, QString InModuleName, QString InSourcePath)
{
  QStringList                           stl;
  QString                               st;
  int                                   n;
  int                                   i;
  int                                   j;
  QString                               st2;
  QString                               name;
  
  n = InSourcePath.length();
  name = InName;
  if ( name.left(n) == InSourcePath ) {
    name = name.sliced(n);
    while (name[0] == '/' ) {
      name = name.sliced(1);
    }
    return name;
  }
  if ( name[0] == '/' ) {
    name = name.sliced(1);
    return name;
  }
  st = InModuleName + QString("/") + name;
  stl = st.split("/");

  st2 = QString();
  n = stl.size();

  for ( i = 0 ; i < n ; i++ ) {
    j = i + 1;
    if ( j < n ) {
      if ( stl[j] == ".." ) {
        i = j;
        continue;
      }
    }
    if ( !st2.isEmpty() ) {
      st2 += "/";
    }
    st2 += stl[i];
  }         
  return st2;
}


