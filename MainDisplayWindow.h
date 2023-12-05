/*****************************************************************************
 * FILE NAME    : MainDisplayWindow.h
 * DATE         : November 29 2023
 * PROJECT      : CodeMerge
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _maindisplaywindow_h_
#define _maindisplaywindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "TrackViewWindow.h"
#include "ModuleWindow.h"
#include "MainControlBar.h"
#include "MainMessageWindow.h"
#include "TrackViewContainer.h"
#include "MainDisplaySplitter.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/

/*****************************************************************************!
 * Exported Class : MainDisplayWindow
 *****************************************************************************/
class MainDisplayWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  MainDisplayWindow             ();

 //! Destructor
 public :
  ~MainDisplayWindow            ();

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
  void                          Initialize              ();
  void                          InitializeSubWindows    ();
  void                          CreateSubWindows        ();
  void                          resizeEvent             (QResizeEvent* InEvent);
  void                          CreateConnections       (void);

 //! Private Data
 private :
  ModuleWindow*                 moduleWindow;
  MainControlBar*               controlBar;
  TrackViewContainer*           trackViewContainer;
  MainDisplaySplitter*          splitter;
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

 //! Public Actions
 public :

};

#endif /* _maindisplaywindow_h_*/
