/*****************************************************************************
 * FILE NAME    : ASTElementWindowItem.h
 * DATE         : December 05 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _astelementwindowitem_h_
#define _astelementwindowitem_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QTreeWidgetItem>
#include <clang-c/Index.h>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define ASTELEMENT_WINDOW_ITEM_X        200
#define ASTELEMENT_WINDOW_ITEM_Y        200
#define ASTELEMENT_WINDOW_ITEM_WIDTH    200
#define ASTELEMENT_WINDOW_ITEM_HEIGHT   200

/*****************************************************************************!
 * Exported Class : ASTElementWindowItem
 *****************************************************************************/
class ASTElementWindowItem : public QWidget, public QTreeWidgetItem
{
  Q_OBJECT;

 //! Constructors
 public :
  ASTElementWindowItem          ();

 //! Destructor
 public :
  ~ASTElementWindowItem         ();

 //! Public Methods
 public :
  void                          SetCursor               (CXCursor InASTCursor);

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

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _astelementwindowitem_h_*/
