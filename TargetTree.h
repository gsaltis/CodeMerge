/*****************************************************************************
 * FILE NAME    : TargetTree.h
 * DATE         : December 02 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _targettree_h_
#define _targettree_h_

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

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define TARGET_TREE_X                   200
#define TARGET_TREE_Y                   200
#define TARGET_TREE_WIDTH               200
#define TARGET_TREE_HEIGHT              200

/*****************************************************************************!
 * Exported Class : TargetTree
 *****************************************************************************/
class TargetTree : public QTreeWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  TargetTree                    ();

 //! Destructor
 public :
  ~TargetTree                   ();

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

 //! Private Data
 private :

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _targettree_h_*/
