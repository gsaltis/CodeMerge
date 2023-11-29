/*****************************************************************************
 * FILE NAME    : TrackViewWindow.h
 * DATE         : November 29 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _trackviewwindow_h_
#define _trackviewwindow_h_

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

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define TRACK_VIEW_WINDOW_X             200
#define TRACK_VIEW_WINDOW_Y             200
#define TRACK_VIEW_WINDOW_WIDTH         200
#define TRACK_VIEW_WINDOW_HEIGHT        200

/*****************************************************************************!
 * Exported Class : TrackViewWindow
 *****************************************************************************/
class TrackViewWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  TrackViewWindow               (QString InTitleText);

 //! Destructor
 public :
  ~TrackViewWindow              ();

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

 //! Private Data
 private :
  MainWindowHeader*             header;
  QString                       titleText;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _trackviewwindow_h_*/
