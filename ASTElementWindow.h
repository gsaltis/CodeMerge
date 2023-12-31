/*****************************************************************************
 * FILE NAME    : ASTElementWindow.h
 * DATE         : December 04 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _astelementwindow_h_
#define _astelementwindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QTreeWidget>
#include <QWidget>
#include <clang-c/Index.h>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/
#include "ASTElementWindowItem.h"

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define ASTELEMENT_WINDOW_X             200
#define ASTELEMENT_WINDOW_Y             200
#define ASTELEMENT_WINDOW_WIDTH         200
#define ASTELEMENT_WINDOW_HEIGHT        200

#define MAX_WINDOW_ITEMS                128

/*****************************************************************************!
 * Exported Class : ASTElementWindow
 *****************************************************************************/
class ASTElementWindow : public QTreeWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  ASTElementWindow              ();

 //! Destructor
 public :
  ~ASTElementWindow             ();

 //! Public Methods
 public :
  void                          AddItem                 (int InLevel, CXCursor InASTCursor);

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
  ASTElementWindowItem*         items[MAX_WINDOW_ITEMS];
  int                           itemsCount;
 //! Public Slots
 public slots :
  void                          SlotTreeClear           ();

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _astelementwindow_h_*/
