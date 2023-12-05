/*****************************************************************************
 * FILE NAME    : MainDisplayWindow.cpp
 * DATE         : November 29 2023
 * PROJECT      : CodeMerge
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
#include "MainDisplayWindow.h"

/*****************************************************************************!
 * Function : MainDisplayWindow
 *****************************************************************************/
MainDisplayWindow::MainDisplayWindow
() : QWidget()
{
  QPalette				pal;

  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(160, 160, 160)));
  setPalette(pal);
  setAutoFillBackground(true);

  Initialize();
}

/*****************************************************************************!
 * Function : ~MainDisplayWindow
 *****************************************************************************/
MainDisplayWindow::~MainDisplayWindow
()
{
}

/*****************************************************************************!
 * Function : Initialize
 *****************************************************************************/
void
MainDisplayWindow::Initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
  CreateConnections();
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
MainDisplayWindow::InitializeSubWindows()
{
  moduleWindow = NULL;
  controlBar = NULL;
  trackViewContainer = NULL;
  splitter = NULL;
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
MainDisplayWindow::CreateSubWindows()
{
  moduleWindow = new ModuleWindow();
  moduleWindow->setParent(this);
  moduleWindow->setMaximumWidth(MODULE_WINDOW_MAX_WIDTH);
  controlBar = new MainControlBar();
  controlBar->setParent(this);

  trackViewContainer = new TrackViewContainer();
  trackViewContainer->setParent(this);

  splitter = new MainDisplaySplitter();
  splitter->setParent(this);
  splitter->addWidget(moduleWindow);
  splitter->addWidget(trackViewContainer);
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
MainDisplayWindow::resizeEvent
(QResizeEvent* InEvent)
{
  int                                   splitterW;
  int                                   splitterH;
  int                                   splitterY;
  int                                   splitterX;

  int                                   horizontalGap;
  int                                   verticalGap;

  int                                   controlBarH;
  int                                   controlBarW;
  int                                   controlBarY;
  int                                   controlBarX;

  QSize					size;  
  int					width;
  int					height;
  
  size = InEvent->size();
  width = size.width();
  height = size.height();
  verticalGap = 5;
  horizontalGap = 5;

  //!
  controlBarX = horizontalGap;
  controlBarY = verticalGap;
  controlBarW = width - (horizontalGap * 2);
  controlBarH = MAIN_CONTROL_BAR_HEIGHT;

  controlBar->move(controlBarX, controlBarY);
  controlBar->resize(controlBarW, controlBarH);

  splitterX = horizontalGap;
  splitterY = MAIN_CONTROL_BAR_HEIGHT + (verticalGap * 2);
  splitterW = width - (horizontalGap * 2);
  splitterH = height - (MAIN_CONTROL_BAR_HEIGHT + (verticalGap * 3));
  
  splitter->move(splitterX, splitterY);
  splitter->resize(splitterW, splitterH);
}

/*****************************************************************************!
 * Function : CreateConnections
 *****************************************************************************/
void
MainDisplayWindow::CreateConnections(void)
{
  connect(moduleWindow,
          ModuleWindow::SignalErrorMessage,
          this,
          MainDisplayWindow::SlotErrorMessage);

  connect(moduleWindow,
          ModuleWindow::SignalErrorClear,
          this,
          MainDisplayWindow::SlotErrorClear);

  connect(this,
          MainDisplayWindow::SignalErrorMessage,
          trackViewContainer,
          TrackViewContainer::SlotErrorMessage);

  connect(this,
          MainDisplayWindow::SignalErrorClear,
          trackViewContainer,
          TrackViewContainer::SlotErrorClear);

  connect(moduleWindow,
          ModuleWindow::SignalCompileSuccess,
          this,
          MainDisplayWindow::SlotCompileSuccess);
  connect(this,
          MainDisplayWindow::SignalCompileSuccess,
          trackViewContainer,
          TrackViewContainer::SlotCompileSuccess);
}

/*****************************************************************************!
 * Function : SlotErrorMessage
 *****************************************************************************/
void
MainDisplayWindow::SlotErrorMessage
(QString InErrorMessage)
{
  emit SignalErrorMessage(InErrorMessage);
}

/*****************************************************************************!
 * Function : SlotCompileSuccess
 * Purpose  : Pass AST Compile Success Message
 *****************************************************************************/
void
MainDisplayWindow::SlotCompileSuccess
(QString InTrackName, QString InASTPath, QString InFileName, QString InErrors, QString InOutput)
{
  emit SignalCompileSuccess(InTrackName, InASTPath, InFileName, InErrors, InOutput);
}

/*****************************************************************************!
 * Function : GetModuleSet1
 *****************************************************************************/
BuildModuleSet*
MainDisplayWindow::GetModuleSet1(void)
{
  return ModuleSet1;  
}

/*****************************************************************************!
 * Function : SetModuleSet1
 *****************************************************************************/
void
MainDisplayWindow::SetModuleSet1
(BuildModuleSet* InModuleSet1)
{
  ModuleSet1 = InModuleSet1;  
}

/*****************************************************************************!
 * Function : GetModuleSet2
 *****************************************************************************/
BuildModuleSet*
MainDisplayWindow::GetModuleSet2(void)
{
  return ModuleSet2;  
}

/*****************************************************************************!
 * Function : SetModuleSet2
 *****************************************************************************/
void
MainDisplayWindow::SetModuleSet2
(BuildModuleSet* InModuleSet2)
{
  ModuleSet2 = InModuleSet2;  
}

/*****************************************************************************!
 * Function : SetModuleSets
 *****************************************************************************/
void
MainDisplayWindow::SetModuleSets
(BuildModuleSet* InModuleSet1, BuildModuleSet* InModuleSet2)
{
  ModuleSet1 = InModuleSet1;
  ModuleSet2 = InModuleSet2;
  trackViewContainer->SetModuleSets(InModuleSet1, InModuleSet2);
}

/*****************************************************************************!
 * Function : SlotErrorClear
 * Purpose  : Send 'Clear Error Display Window' message 
 *****************************************************************************/
void
MainDisplayWindow::SlotErrorClear()
{
  emit SignalErrorClear();
}
