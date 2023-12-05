/*****************************************************************************
 * FILE NAME    : ModuleContainerWindow.h
 * DATE         : December 02 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _modulecontainerwindow_h_
#define _modulecontainerwindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "ModuleTree.h"
#include "ModuleToolBar.h"
#include "ModuleTreeWindow.h"
#include "SourceTreeWindow.h"
#include "TargetTreeWindow.h"
#include "BuildModuleSet.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MODULE_CONTAINER_WINDOW_X       200
#define MODULE_CONTAINER_WINDOW_Y       200
#define MODULE_CONTAINER_WINDOW_WIDTH   200
#define MODULE_CONTAINER_WINDOW_HEIGHT  200

/*****************************************************************************!
 * Exported Class : ModuleContainerWindow
 *****************************************************************************/
class ModuleContainerWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  ModuleContainerWindow         ();

 //! Destructor
 public :
  ~ModuleContainerWindow        ();

 //! Public Methods
 public :
  void                          AddModuleSet            (BuildModuleSet* InModuleSet1, BuildModuleSet* InModuleSet2);

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
  ModuleToolBar*                toolbar;
  ModuleTreeWindow*             moduleTreeWindow;
  SourceTreeWindow*             sourceTreeWindow;
  TargetTreeWindow*             targetTreeWindow;

 //! Public Slots
 public slots :
  void                          SlotDisplaySource       (void);
  void                          SlotDisplayModules      (void);
  void                          SlotDisplayTargets      (void);
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

#endif /* _modulecontainerwindow_h_*/
