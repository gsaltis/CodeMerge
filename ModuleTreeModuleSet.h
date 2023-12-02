/*****************************************************************************
 * FILE NAME    : ModuleTreeModuleSet.h
 * DATE         : December 01 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _moduletreemoduleset_h_
#define _moduletreemoduleset_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QTreeWidgetItem>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "BuildModuleSet.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MODULE_TREE_MODULE_SET_WIDGET_X 200
#define MODULE_TREE_MODULE_SET_WIDGET_Y 200
#define MODULE_TREE_MODULE_SET_WIDGET_WIDTH 200
#define MODULE_TREE_MODULE_SET_WIDGET_HEIGHT 200

/*****************************************************************************!
 * Exported Class : ModuleTreeModuleSet
 *****************************************************************************/
class ModuleTreeModuleSet : public QTreeWidgetItem
{
 //! Constructors
 public :
  ModuleTreeModuleSet     (BuildModuleSet* InModuleSet1, BuildModuleSet* InModuleSet2);

 //! Destructor
 public :
  ~ModuleTreeModuleSet    ();

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
  void                          CreateModules           (void);

 //! Private Data
 private :
  BuildModuleSet*               ModuleSet1;
  BuildModuleSet*               ModuleSet2;

};

#endif /* _moduletreemoduleset_h_*/
