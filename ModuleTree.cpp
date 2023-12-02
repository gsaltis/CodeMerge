/*****************************************************************************
 * FILE NAME    : ModuleTree.cpp
 * DATE         : December 01 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "ModuleTree.h"
#include "ModuleTreeModuleSet.h"

/*****************************************************************************!
 * Function : ModuleTree
 *****************************************************************************/
ModuleTree::ModuleTree
() : QTreeWidget()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 192)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~ModuleTree
 *****************************************************************************/
ModuleTree::~ModuleTree
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
ModuleTree::initialize()
{
  setColumnCount(2);
  InitializeSubWindows();  
  CreateSubWindows();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
ModuleTree::CreateSubWindows()
{
  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
ModuleTree::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
ModuleTree::resizeEvent
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
ModuleTree::AddModuleSet
(BuildModuleSet* InModuleSet1, BuildModuleSet* InModuleSet2)
{
  ModuleTreeModuleSet*                  treeItem;

  treeItem = new ModuleTreeModuleSet(InModuleSet1, InModuleSet2);
  addTopLevelItem(treeItem);
}
