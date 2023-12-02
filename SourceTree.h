/*****************************************************************************
 * FILE NAME    : SourceTree.h
 * DATE         : December 02 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _sourcetree_h_
#define _sourcetree_h_

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
#define SOURCE_TREE_X                   200
#define SOURCE_TREE_Y                   200
#define SOURCE_TREE_WIDTH               200
#define SOURCE_TREE_HEIGHT              200

/*****************************************************************************!
 * Exported Class : SourceTree
 *****************************************************************************/
class SourceTree : public QTreeWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  SourceTree                    ();

 //! Destructor
 public :
  ~SourceTree                   ();

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

#endif /* _sourcetree_h_*/
