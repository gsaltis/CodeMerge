/*****************************************************************************
 * FILE NAME    : TrackViewContainer.h
 * DATE         : December 02 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _trackviewcontainer_h_
#define _trackviewcontainer_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MainMessageWindow.h"
#include "TrackViewWindow.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define TRACK_VIEW_CONTAINER_X          200
#define TRACK_VIEW_CONTAINER_Y          200
#define TRACK_VIEW_CONTAINER_WIDTH      200
#define TRACK_VIEW_CONTAINER_HEIGHT     200

/*****************************************************************************!
 * Exported Class : TrackViewContainer
 *****************************************************************************/
class TrackViewContainer : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  TrackViewContainer            ();

 //! Destructor
 public :
  ~TrackViewContainer           ();

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
  MainMessageWindow*            messageWindow;
  TrackViewWindow*              track2Window;
  TrackViewWindow*              track3Window;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _trackviewcontainer_h_*/
