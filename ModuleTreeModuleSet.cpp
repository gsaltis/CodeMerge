/*****************************************************************************
 * FILE NAME    : ModuleTreeModuleSet.cpp
 * DATE         : December 01 2023
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
#include "ModuleTreeModuleSet.h"
#include "StringTuple.h"

/*****************************************************************************!
 * Function : ModuleTreeModuleSet
 *****************************************************************************/
ModuleTreeModuleSet::ModuleTreeModuleSet
(BuildModuleSet* InModuleSet1, BuildModuleSet* InModuleSet2) : QTreeWidgetItem()
{
  QPalette pal;
  initialize();
  ModuleSet1 = InModuleSet1;
  ModuleSet2 = InModuleSet2;

  setText(0, ModuleSet1->GetTrackName());
  setText(1, ModuleSet2->GetTrackName());
  CreateModules();
}

/*****************************************************************************!
 * Function : ~ModuleTreeModuleSet
 *****************************************************************************/
ModuleTreeModuleSet::~ModuleTreeModuleSet
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
ModuleTreeModuleSet::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
ModuleTreeModuleSet::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
ModuleTreeModuleSet::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
ModuleTreeModuleSet::resizeEvent
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
 * Function : CreateModules
 *****************************************************************************/
void
ModuleTreeModuleSet::CreateModules(void)
{
  QString                               s2;
  QString                               s1;
  int                                   j;
  int                                   m;
  bool                                  found;
  BuildModule*                          mod;
  int                                   i;
  int                                   n;
  QList<StringTuple*>                   strings;
  QString                               name;
  StringTuple*                          st;
  QTreeWidgetItem*                      item;
  
  n = ModuleSet1->GetBuildModulesCount();

  //! Add all names from first track
  for ( i = 0; i < n; i++ ) {
    mod = ModuleSet1->GetBuildModuleByIndex(i);
    name = mod->GetName();
    st = new StringTuple(name, QString());
    strings << st;
  }

  //! Walk module set 2 modules
  n = ModuleSet2->GetBuildModulesCount();
  for (i = 0; i < n; i++) {
    mod = ModuleSet2->GetBuildModuleByIndex(i);
    name = mod->GetName();
    m = strings.size();
    found = false;

    //! Check if this name is already on the list 
    for ( j = 0 ; j < m ; j++ ) {
      st = strings[j];
      if ( st->GetString1() == name ) {

        //! Add the second track name
        st->SetString2(name);
        found = true;
        break;
      }
    }
    if ( found ) {
      continue;
    }

    // Add a second track only name
    st = new StringTuple(QString(), name);
    strings << st;
  }

  n = strings.size();

  // Build the tree widgets
  for ( i = 0 ; i < n ; i++ ) {
    st = strings[i];

    item = new QTreeWidgetItem();
    s1 = st->GetString1();
    s2 = st->GetString2();
    item->setText(0, s1);
    item->setText(1, s2);
    addChild(item);
  }
}
