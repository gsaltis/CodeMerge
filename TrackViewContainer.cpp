/*****************************************************************************
 * FILE NAME    : TrackViewContainer.cpp
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
#include "TrackViewContainer.h"
#include "ModuleWindow.h"

/*****************************************************************************!
 * Function : TrackViewContainer
 *****************************************************************************/
TrackViewContainer::TrackViewContainer
() : QWidget()
{
  QPalette pal;
  pal = palette();
  pal.setBrush(QPalette::Window, QBrush(QColor(160, 160, 160)));
  setPalette(pal);
  setAutoFillBackground(true);
  initialize();
}

/*****************************************************************************!
 * Function : ~TrackViewContainer
 *****************************************************************************/
TrackViewContainer::~TrackViewContainer
()
{
}

/*****************************************************************************!
 * Function : initialize
 *****************************************************************************/
void
TrackViewContainer::initialize()
{
  InitializeSubWindows();  
  CreateSubWindows();
  CreateConnections();
}

/*****************************************************************************!
 * Function : CreateSubWindows
 *****************************************************************************/
void
TrackViewContainer::CreateSubWindows()
{
  track2Window = new TrackViewWindow("Track 2");
  track2Window->setParent(this);
  
  track3Window = new TrackViewWindow("Track 3");
  track3Window->setParent(this);
  
  messageWindow = new MainMessageWindow();
  messageWindow->setParent(this);  
}

/*****************************************************************************!
 * Function : InitializeSubWindows
 *****************************************************************************/
void
TrackViewContainer::InitializeSubWindows()
{
  
}

/*****************************************************************************!
 * Function : resizeEvent
 *****************************************************************************/
void
TrackViewContainer::resizeEvent
(QResizeEvent* InEvent)
{
  QSize					size;  
  int					width;
  int					height;

  int                                   w;
  
  int                                   messageWindowW;
  int                                   messageWindowH;
  int                                   messageWindowY;
  int                                   messageWindowX;

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
  
  verticalGap = 5;
  horizontalGap = 5;
  
  size = InEvent->size();
  width = size.width();
  height = size.height();

  w = width - horizontalGap;
  w /= 2;
  
  track2WindowX = 0;
  track2WindowY = 0;
  track2WindowH = height - (MAIN_MESSAGE_WINDOW_HEIGHT + verticalGap);
  track2WindowW = w;

  track3WindowX = w + horizontalGap;
  track3WindowY = 0;
  track3WindowH = height - (MAIN_MESSAGE_WINDOW_HEIGHT + verticalGap);
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
  messageWindowX = 0;
  messageWindowY = height - (MAIN_MESSAGE_WINDOW_HEIGHT);
  messageWindowW = width;
  messageWindowH = MAIN_MESSAGE_WINDOW_HEIGHT;
  
  messageWindow->move(messageWindowX, messageWindowY);
  messageWindow->resize(messageWindowW, messageWindowH);

}

/*****************************************************************************!
 * Function : SlotErrorMessage
 *****************************************************************************/
void
TrackViewContainer::SlotErrorMessage
(QString InErrorMessage)
{
  emit SignalErrorMessage(InErrorMessage);
}

/*****************************************************************************!
 * Function : CreateConnections
 *****************************************************************************/
void
TrackViewContainer::CreateConnections(void)
{
  connect(this,
          TrackViewContainer::SignalErrorMessage,
          messageWindow,
          MainMessageWindow::SlotErrorMessage);
  connect(this,
          TrackViewContainer::SignalCompileSuccess,
          track2Window,
          TrackViewWindow::SlotCompileSuccess);
}

/*****************************************************************************!
 * Function : SlotCompileSuccess
 * Purpose  : Pass AST Compile Success Message
 *****************************************************************************/
void
TrackViewContainer::SlotCompileSuccess
(QString InTrackName, QString InASTPath, QString InFileName, QString InErrors, QString InOutput)
{
  TRACE_FUNCTION_START();
  TRACE_FUNCTION_QSTRING(InTrackName);
  if ( InTrackName == "Track2" ) {
    track2Window->SlotCompileSuccess(InASTPath, InFileName, InErrors, InOutput);
    TRACE_FUNCTION_END();
    return;
  }
  if ( InTrackName == "Track3" ) {
    track3Window->SlotCompileSuccess(InASTPath, InFileName, InErrors, InOutput);
  }
  TRACE_FUNCTION_END();
}

/*****************************************************************************!
 * Function : GetModuleSet1
 *****************************************************************************/
BuildModuleSet*
TrackViewContainer::GetModuleSet1(void)
{
  return ModuleSet1;  
}

/*****************************************************************************!
 * Function : SetModuleSet1
 *****************************************************************************/
void
TrackViewContainer::SetModuleSet1
(BuildModuleSet* InModuleSet1)
{
  ModuleSet1 = InModuleSet1;  
}

/*****************************************************************************!
 * Function : GetModuleSet2
 *****************************************************************************/
BuildModuleSet*
TrackViewContainer::GetModuleSet2(void)
{
  return ModuleSet2;  
}

/*****************************************************************************!
 * Function : SetModuleSet2
 *****************************************************************************/
void
TrackViewContainer::SetModuleSet2
(BuildModuleSet* InModuleSet2)
{
  ModuleSet2 = InModuleSet2;  
}

/*****************************************************************************!
 * Function : SetModuleSets
 *****************************************************************************/
void
TrackViewContainer::SetModuleSets
(BuildModuleSet* InModuleSet1, BuildModuleSet* InModuleSet2)
{
  ModuleSet1 = InModuleSet1;  
  ModuleSet2 = InModuleSet2;
  track2Window->SetModuleSet(InModuleSet1);
  track3Window->SetModuleSet(InModuleSet2);
}
