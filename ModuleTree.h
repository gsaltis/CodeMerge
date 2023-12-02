/*****************************************************************************
 * FILE NAME    : ModuleTree.h
 * DATE         : December 01 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _moduletree_h_
#define _moduletree_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QTreeWidget>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "BuildModuleSet.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MODULE_TREE_X                   200
#define MODULE_TREE_Y                   200
#define MODULE_TREE_WIDTH               200
#define MODULE_TREE_HEIGHT              200

/*****************************************************************************!
 * Exported Class : ModuleTree
 *****************************************************************************/
class ModuleTree : public QTreeWidget
{
  Q_OBJECT;

  //! Constructors
public :
  ModuleTree                    ();

  //! Destructor
public :
  ~ModuleTree                   ();

  //! Public Methods
public :
  void                          AddModuleSet            (BuildModuleSet* InModuleSet1,
                                                         BuildModuleSet* InModuleSet2);

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

  //! Public Slots
public slots :

  //! Public Signals
signals :

  //! Public Actions
public :

};

#endif /* _moduletree_h_*/
