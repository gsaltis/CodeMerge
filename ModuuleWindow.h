/*****************************************************************************
 * FILE NAME    : ModuuleWindow.h
 * DATE         : November 29 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _moduulewindow_h_
#define _moduulewindow_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MODUULE_WINDOW_X                200
#define MODUULE_WINDOW_Y                200
#define MODUULE_WINDOW_WIDTH            200
#define MODUULE_WINDOW_HEIGHT           200

/*****************************************************************************!
 * Exported Class : ModuuleWindow
 *****************************************************************************/
class ModuuleWindow : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  ModuuleWindow                 ();

 //! Destructor
 public :
  ~ModuuleWindow                ();

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

#endif /* _moduulewindow_h_*/
