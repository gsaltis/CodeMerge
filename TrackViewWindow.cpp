/*****************************************************************************
 * FILE NAME    : TrackViewWindow.cpp
 * DATE         : November 29 2023
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
#include "TrackViewWindow.h"

/*****************************************************************************!
 * Function : TrackViewWindow
 *****************************************************************************/
TrackViewWindow::TrackViewWindow
(QString InTitleText) : QWidget()
{
  QPalette pal;

  titleText = InTitleText;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(255, 255, 255)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~TrackViewWindow
 *****************************************************************************/
TrackViewWindow::~TrackViewWindow
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
TrackViewWindow::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
  CreateConnections();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
TrackViewWindow::CreateSubWindows()
{
  header = new MainWindowHeader(titleText, this);
  astWindow = new ASTDisplayWindow();
  astWindow->setParent(this);
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
TrackViewWindow::InitializeSubWindows()
{
  header = NULL;  
  astWindow = NULL;
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
TrackViewWindow::resizeEvent
(QResizeEvent* InEvent)
{
  int                                   astWindowW;
  int                                   astWindowH;
  int                                   astWindowY;
  int                                   astWindowX;
  int                                   headerW;
  int                                   headerH;
  int                                   headerY;
  int                                   headerX;
  QSize					size;  
  int					width;
  int					height;

  size = InEvent->size();
  width = size.width();
  height = size.height();
  (void)height;
  (void)width;

  headerX = 0;
  headerY = 0;
  headerW = width;
  headerH = MAIN_WINDOW_HEADER_HEIGHT;
  
  header->move(headerX, headerY);
  header->resize(headerW, headerH);

  astWindowX = 0;
  astWindowY = MAIN_WINDOW_HEADER_HEIGHT;
  astWindowW = width;
  astWindowH = height - MAIN_WINDOW_HEADER_HEIGHT;
  astWindow->move(astWindowX, astWindowY);
  astWindow->resize(astWindowW, astWindowH);
}

/*****************************************************************************!
 * Function : SlotCompileSuccess
 * Purpose  : Pass AST Compile Success Message
 *****************************************************************************/
void
TrackViewWindow::SlotCompileSuccess
(QString InASTPath, QString InFileName, QString InErrors, QString InOutput)
{
  QString                               trackName;
  QString                               windowTitle;
  QString                               filePath;
  QString                               st;
  int                                   n;
  QString                               trackPath;

  trackPath = ModuleSet->GetTrackPath();
  n = trackPath.length();
  st = InFileName.left(n);
  if ( trackPath == st ) {
    filePath = InFileName.sliced(n);
  }
  trackName = ModuleSet->GetTrackName();
  windowTitle = trackName + " - " + filePath;
  header->SetText(windowTitle);
  emit SignalCompileSuccess(InASTPath, InFileName, InErrors, InOutput);
}

/*****************************************************************************!
 * Function : CreateConnections
 *****************************************************************************/
void
TrackViewWindow::CreateConnections(void)
{
  connect(this,
          TrackViewWindow::SignalCompileSuccess,
          astWindow,
          ASTDisplayWindow::SlotCompileSuccess);
  connect(this,
          TrackViewWindow::SignalTreeClear,
          astWindow,
          ASTDisplayWindow::SlotTreeClear);
}

/*****************************************************************************!
 * Function : GetModuleSet
 *****************************************************************************/
BuildModuleSet*
TrackViewWindow::GetModuleSet(void)
{
  return ModuleSet;  
}

/*****************************************************************************!
 * Function : SetModuleSet
 *****************************************************************************/
void
TrackViewWindow::SetModuleSet
(BuildModuleSet* InModuleSet)
{
  ModuleSet = InModuleSet;  
}

/*****************************************************************************!
 * Function : SlotTreeClear
 * Purpose  : Send 'Clear Source Tree Window' message 
 *****************************************************************************/
void
TrackViewWindow::SlotTreeClear()
{
  emit SignalTreeClear();
}
