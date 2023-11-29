/*****************************************************************************
 * FILE NAME    : MainDisplayWindow.cpp
 * DATE         : November 29 2023
 * PROJECT      : CodeMerge
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
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
MainDisplayWindow::InitializeSubWindows()
{
  track2Window = NULL;  
  track3Window = NULL;
  moduleWindow = NULL;
  controlBar = NULL;
  messageWindow = NULL;
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
MainDisplayWindow::CreateSubWindows()
{
  track2Window = new TrackViewWindow("Track 2");
  track2Window->setParent(this);
  track3Window = new TrackViewWindow("Track 3");
  track3Window->setParent(this);
  moduleWindow = new ModuleWindow();
  moduleWindow->setParent(this);
  controlBar = new MainControlBar();
  controlBar->setParent(this);
  messageWindow = new MainMessageWindow();
  messageWindow->setParent(this);
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
MainDisplayWindow::resizeEvent
(QResizeEvent* InEvent)
{
  int                                   messageWindowW;
  int                                   messageWindowH;
  int                                   messageWindowY;
  int                                   messageWindowX;
  int                                   w;
  int                                   track2WindowX;
  int                                   track2WindowY;
  int                                   track2WindowW;
  int                                   track2WindowH;

  int                                   track3WindowX;
  int                                   track3WindowY;
  int                                   track3WindowW;
  int                                   track3WindowH;

  int                                   horizontalGap;
  int                                   verticalGap;
  int                                   controlBarH;
  int                                   controlBarW;
  int                                   controlBarY;
  int                                   controlBarX;

  int                                   moduleWindowH;
  int                                   moduleWindowW;
  int                                   moduleWindowY;
  int                                   moduleWindowX;
  
  QSize					size;  
  int					width;
  int					height;
  
  size = InEvent->size();
  width = size.width();
  height = size.height();
  verticalGap = 5;
  horizontalGap = 5;

  w = width - (MODULE_WINDOW_WIDTH + (horizontalGap * 4));
  w /= 2;
  
  track2WindowX = MODULE_WINDOW_WIDTH + (horizontalGap * 2);
  track2WindowY = MAIN_CONTROL_BAR_HEIGHT + (verticalGap * 2);
  track2WindowH = height - (MAIN_CONTROL_BAR_HEIGHT + MAIN_MESSAGE_WINDOW_HEIGHT + verticalGap * 4);
  track2WindowW = w;

  track3WindowX = MODULE_WINDOW_WIDTH + w + (horizontalGap * 3);
  track3WindowY = MAIN_CONTROL_BAR_HEIGHT + (verticalGap * 2);
  track3WindowH = height - (MAIN_CONTROL_BAR_HEIGHT + MAIN_MESSAGE_WINDOW_HEIGHT + verticalGap * 4);
  track3WindowW = w;
  
  if ( track2Window ) {
    track2Window->move(track2WindowX, track2WindowY);
    track2Window->resize(track2WindowW, track2WindowH);
  }
  if ( track3Window ) {
    track3Window->move(track3WindowX, track3WindowY);
    track3Window->resize(track3WindowW, track3WindowH);
  }

  //!
  moduleWindowX = horizontalGap;
  moduleWindowY = MAIN_CONTROL_BAR_HEIGHT + (verticalGap * 2);
  moduleWindowW = MODULE_WINDOW_WIDTH;
  moduleWindowH = height - (MAIN_CONTROL_BAR_HEIGHT + verticalGap * 3);

  moduleWindow->move(moduleWindowX, moduleWindowY);
  moduleWindow->resize(moduleWindowW, moduleWindowH);

  //!
  controlBarX = horizontalGap;
  controlBarY = verticalGap;
  controlBarW = width - (horizontalGap * 2);
  controlBarH = MAIN_CONTROL_BAR_HEIGHT;

  controlBar->move(controlBarX, controlBarY);
  controlBar->resize(controlBarW, controlBarH);

  //!
  messageWindowX = MODULE_WINDOW_WIDTH + (horizontalGap * 2);
  messageWindowY = height - (MAIN_MESSAGE_WINDOW_HEIGHT + horizontalGap);
  messageWindowW = width - (MODULE_WINDOW_WIDTH + horizontalGap * 3);
  messageWindowH = MAIN_MESSAGE_WINDOW_HEIGHT;
  
  messageWindow->move(messageWindowX, messageWindowY);
  messageWindow->resize(messageWindowW, messageWindowH);
}
