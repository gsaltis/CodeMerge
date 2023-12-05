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
  BuildModuleSet*               GetModuleSet1           (void);
  void                          SetModuleSet1           (BuildModuleSet* InModuleSet1);
  BuildModuleSet*               GetModuleSet2           (void);
  void                          SetModuleSet2           (BuildModuleSet* InModuleSet2);
  void                          SetModuleSets           (BuildModuleSet* InModuleSet1, BuildModuleSet* InModuleSet2);

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
  void                          CreateConnections       (void);

 //! Private Data
 private :
  MainMessageWindow*            messageWindow;
  TrackViewWindow*              track2Window;
  TrackViewWindow*              track3Window;
  BuildModuleSet*               ModuleSet1;
  BuildModuleSet*               ModuleSet2;

 //! Public Slots
 public slots :
  void                          SlotErrorMessage        (QString InErrorMessage);
  void                          SlotCompileSuccess      (QString InTrackName, QString InASTPath, QString InFileName, QString InErrors, QString InOutput);
  void                          SlotErrorClear          ();

 //! Public Signals
 signals :
  void                          SignalErrorMessage      (QString InErrorMessage);
  void                          SignalCompileSuccess    (QString InTrackName, QString InASTPath, QString InFileName, QString InErrors, QString InOutput);
  void                          SignalErrorClear        ();
  void                          SignalTreeClear         ();

 //! Public Actions
 public :

};

#endif /* _trackviewcontainer_h_*/
