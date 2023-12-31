/*****************************************************************************
 * FILE NAME    : MainWindow.h
 * DATE         : November 29 2023
 * PROJECT      : CodeMerge
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _mainwindow_h_
#define _mainwindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QMainWindow>
#include <QAction>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "MainDisplayWindow.h"
#include "SystemConfig.h"
#include "BuildModuleSet.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MAIN_WINDOW_WIDTH                       640
#define MAIN_WINDOW_HEIGHT                      480
#define MAIN_WINDOW_Y                           100
#define MAIN_WINDOW_X                           100

/*****************************************************************************!
 * Exported Class : MainWindow
 *****************************************************************************/
class MainWindow : public QMainWindow
{
  Q_OBJECT;

 //! Constructors
 public :
  MainWindow                    ();
  MainWindow                    (QWidget* );

 //! Destructor
 public :
  ~MainWindow                   ();

 //! Public Methods
 public :
  void                          SetModuleSets           (BuildModuleSet* ModuleSet1, BuildModuleSet* ModuleSet2);

 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          Initialize              ();
  void                          CreateSubWindows        ();
  void                          InitializeSubWindows    ();
  void                          resizeEvent             (QResizeEvent* InEvent);
  void                          CreateActions           ();
  void                          CreateMenus             ();
  void                          moveEvent               (QMoveEvent* InEvent);

 //! Private Data
 private :
  MainDisplayWindow*            displayWindow;
  QMenuBar*                     menubar;
  QMenu*                        fileMenu;
  QStatusBar*                   statusbar;

 //! Public Slots
 public slots :
  void                          SlotExit                (void);

 //! Public Signals
 signals :
  void                          SignalErrorClear        ();

 //! Public Actions
 public :
  QAction*                      ActionExit;

};

#endif /* _mainwindow_h_*/
