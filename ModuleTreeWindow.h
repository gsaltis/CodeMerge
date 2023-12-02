/*****************************************************************************
 * FILE NAME    : ModuleTreeWindow.h
 * DATE         : December 02 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _moduletreewindow_h_
#define _moduletreewindow_h_

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
#include "ModuleTree.h"
#include "BuildModuleSet.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MODULE_TREE_WINDOW_X            200
#define MODULE_TREE_WINDOW_Y            200
#define MODULE_TREE_WINDOW_WIDTH        200
#define MODULE_TREE_WINDOW_HEIGHT       200

/*****************************************************************************!
 * Exported Class : ModuleTreeWindow
 *****************************************************************************/
class ModuleTreeWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  ModuleTreeWindow              ();

 //! Destructor
 public :
  ~ModuleTreeWindow             ();

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

 //! Private Data
 private :
  MainWindowHeader*             header;
  ModuleTree*                   moduleTree;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _moduletreewindow_h_*/
