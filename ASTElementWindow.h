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
#include <QTextEdit>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define ASTELEMENT_WINDOW_X             200
#define ASTELEMENT_WINDOW_Y             200
#define ASTELEMENT_WINDOW_WIDTH         200
#define ASTELEMENT_WINDOW_HEIGHT        200

/*****************************************************************************!
 * Exported Class : ASTElementWindow
 *****************************************************************************/
class ASTElementWindow : public QTextEdit
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

#endif /* _astelementwindow_h_*/
