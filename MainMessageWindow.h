/*****************************************************************************
 * FILE NAME    : MainMessageWindow.h
 * DATE         : November 29 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _mainmessagewindow_h_
#define _mainmessagewindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MainWindowHeader.h"
#include "CompileErrorDisplay.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MAIN_MESSAGE_WINDOW_X           200
#define MAIN_MESSAGE_WINDOW_Y           200
#define MAIN_MESSAGE_WINDOW_WIDTH       200
#define MAIN_MESSAGE_WINDOW_HEIGHT      300

/*****************************************************************************!
 * Exported Class : MainMessageWindow
 *****************************************************************************/
class MainMessageWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  MainMessageWindow             ();

 //! Destructor
 public :
  ~MainMessageWindow            ();

 //! Public Methods
 public :

 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          initialize              ();
  void                          CreateSubWindows        ();
  void                          InitializeSubWindows    ();
  void                          resizeEvent             (QResizeEvent* InEvent);
  void                          paintEvent              (QPaintEvent* InEvent);
  void                          CreateConnections       (void);

 //! Private Data
 private :
  MainWindowHeader*             header;
  QColor                        EndingColor;
  QColor                        StartingColor;
  CompileErrorDisplay*          compileErrorText;

 //! Public Slots
 public slots :
  void                          SlotErrorMessage        (QString InErrorMessage);

 //! Public Signals
 signals :
  void                          SignalErrorMessage      (QString InErrorMessage);

 //! Public Actions
 public :

};

#endif /* _mainmessagewindow_h_*/
