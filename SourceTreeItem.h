/*****************************************************************************
 * FILE NAME    : SourceTreeItem.h
 * DATE         : December 03 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _sourcetreeitem_h_
#define _sourcetreeitem_h_

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
#define SOURCE_TREE_ITEM_X              200
#define SOURCE_TREE_ITEM_Y              200
#define SOURCE_TREE_ITEM_WIDTH          200
#define SOURCE_TREE_ITEM_HEIGHT         200

/*****************************************************************************!
 * Exported Class : SourceTreeItem
 *****************************************************************************/
class SourceTreeItem : public QTreeWidgetItem
{
 //! Constructors
 public :
  SourceTreeItem                (QString InText);

 //! Destructor
 public :
  ~SourceTreeItem               ();

 //! Public Methods
 public :
  QString                       GetText                 (void);
  void                          SetText                 (QString InText);
  BuildModuleSet*               GetModuleSet1           (void);
  void                          SetModuleSet1           (BuildModuleSet* InModuleSet1);
  BuildModuleSet*               GetModuleSet2           (void);
  void                          SetModuleSet2           (BuildModuleSet* InModuleSet2);
  void                          ProcessSelected         (void);

 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :
  void                          initialize              ();

 //! Private Data
 private :
  QString                       text;
  BuildModuleSet*               moduleSet1;
  BuildModuleSet*               moduleSet2;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _sourcetreeitem_h_*/
