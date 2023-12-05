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
#include "ASTDisplayWindow.h"
#include "BuildModuleSet.h"

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
  BuildModuleSet*               GetModuleSet            (void);
  void                          SetModuleSet            (BuildModuleSet* InModuleSet);

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
  MainWindowHeader*             header;
  QString                       titleText;
  ASTDisplayWindow*             astWindow;
  BuildModuleSet*               ModuleSet;

 //! Public Slots
 public slots :
  void                          SlotCompileSuccess      (QString InASTPath, QString InFileName, QString InErrors, QString InOutput);
  void                          SlotTreeClear           ();

 //! Public Signals
 signals :
  void                          SignalCompileSuccess    (QString InASTPath, QString InFileName, QString InErrors, QString InOutput);
  void                          SignalTreeClear         ();

 //! Public Actions
 public :

};

#endif /* _trackviewwindow_h_*/
