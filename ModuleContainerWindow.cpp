/*****************************************************************************
 * FILE NAME    : ModuleContainerWindow.cpp
 * DATE         : December 02 2023
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
#include "ModuleContainerWindow.h"

/*****************************************************************************!
 * Function : ModuleContainerWindow
 *****************************************************************************/
ModuleContainerWindow::ModuleContainerWindow
() : QWidget()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~ModuleContainerWindow
 *****************************************************************************/
ModuleContainerWindow::~ModuleContainerWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
ModuleContainerWindow::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
  CreateConnections();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
ModuleContainerWindow::CreateSubWindows()
{
  toolbar = new ModuleToolBar();
  toolbar->setParent(this);

  moduleTreeWindow = new ModuleTreeWindow();
  moduleTreeWindow->setParent(this);
  sourceTreeWindow = new SourceTreeWindow();
  sourceTreeWindow->setParent(this);
  sourceTreeWindow->hide();
  targetTreeWindow = new TargetTreeWindow();
  targetTreeWindow->setParent(this);
  targetTreeWindow->hide();
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
ModuleContainerWindow::InitializeSubWindows()
{
  toolbar = NULL;
  moduleTreeWindow = NULL;
  sourceTreeWindow = NULL;
  targetTreeWindow = NULL;
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
ModuleContainerWindow::resizeEvent
(QResizeEvent* InEvent)
{
  int                                   targetTreeWindowW;
  int                                   targetTreeWindowH;
  int                                   targetTreeWindowY;
  int                                   targetTreeWindowX;
  int                                   sourceTreeWindowW;
  int                                   sourceTreeWindowH;
  int                                   sourceTreeWindowY;
  int                                   sourceTreeWindowX;
  int                                   moduleTreeWindowW;
  int                                   moduleTreeWindowH;
  int                                   moduleTreeWindowY;
  int                                   moduleTreeWindowX;
  
  int                                   toolbarW;
  int                                   toolbarH;
  int                                   toolbarY;
  int                                   toolbarX;

  QSize					size;  
  int					width;
  int					height;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  (void)height;
  (void)width;

  toolbarX = 0;
  toolbarY = height - MODULE_TOOL_BAR_HEIGHT;
  toolbarW = width;
  toolbarH = MODULE_TOOL_BAR_HEIGHT;
  toolbar->move(toolbarX, toolbarY);
  toolbar->resize(toolbarW, toolbarH);

  moduleTreeWindowX = 0;
  moduleTreeWindowY = 0;
  moduleTreeWindowW = width;
  moduleTreeWindowH = height - MODULE_TOOL_BAR_HEIGHT;
  moduleTreeWindow->move(moduleTreeWindowX, moduleTreeWindowY);
  moduleTreeWindow->resize(moduleTreeWindowW, moduleTreeWindowH);

  sourceTreeWindowX = 0;
  sourceTreeWindowY = 0;
  sourceTreeWindowW = width;
  sourceTreeWindowH = height - MODULE_TOOL_BAR_HEIGHT;
  sourceTreeWindow->move(sourceTreeWindowX, sourceTreeWindowY);
  sourceTreeWindow->resize(sourceTreeWindowW, sourceTreeWindowH);

  targetTreeWindowX = 0;
  targetTreeWindowY = 0;
  targetTreeWindowW = width;
  targetTreeWindowH = height - MODULE_TOOL_BAR_HEIGHT;
  targetTreeWindow->move(targetTreeWindowX, targetTreeWindowY);
  targetTreeWindow->resize(targetTreeWindowW, targetTreeWindowH);
}

/*****************************************************************************!
 * Function : AddModuleSet
 *****************************************************************************/
void
ModuleContainerWindow::AddModuleSet
(BuildModuleSet* InModuleSet1, BuildModuleSet* InModuleSet2)
{
  moduleTreeWindow->AddModuleSet(InModuleSet1, InModuleSet2);
  sourceTreeWindow->AddModuleSet(InModuleSet1, InModuleSet2);
}

/*****************************************************************************!
 * Function : CreateConnections
 *****************************************************************************/
void
ModuleContainerWindow::CreateConnections(void)
{
  connect(toolbar,
          ModuleToolBar::SignalDisplaySource,
          this,
          ModuleContainerWindow::SlotDisplaySource);
  
  connect(toolbar,
          ModuleToolBar::SignalDisplayTargets,
          this,
          ModuleContainerWindow::SlotDisplayTargets);
  
  connect(toolbar,
          ModuleToolBar::SignalDisplayModules,
          this,
          ModuleContainerWindow::SlotDisplayModules);
}

/*****************************************************************************!
 * Function : SlotDisplaySource
 *****************************************************************************/
void
ModuleContainerWindow::SlotDisplaySource(void)
{
  moduleTreeWindow->hide();
  sourceTreeWindow->show();
  targetTreeWindow->hide();
}

/*****************************************************************************!
 * Function : SlotDisplayModules
 *****************************************************************************/
void
ModuleContainerWindow::SlotDisplayModules(void)
{
  moduleTreeWindow->show();
  sourceTreeWindow->hide();  
  targetTreeWindow->hide();
}

/*****************************************************************************!
 * Function : SlotDisplayTargets
 *****************************************************************************/
void
ModuleContainerWindow::SlotDisplayTargets(void)
{
  moduleTreeWindow->hide();
  sourceTreeWindow->hide();  
  targetTreeWindow->show();
  
}
