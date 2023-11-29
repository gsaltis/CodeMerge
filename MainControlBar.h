/*****************************************************************************
 * FILE NAME    : MainControlBar.h
 * DATE         : November 29 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _maincontrolbar_h_
#define _maincontrolbar_h_

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
#define MAIN_CONTROL_BAR_X              200
#define MAIN_CONTROL_BAR_Y              200
#define MAIN_CONTROL_BAR_WIDTH          200
#define MAIN_CONTROL_BAR_HEIGHT         25

/*****************************************************************************!
 * Exported Class : MainControlBar
 *****************************************************************************/
class MainControlBar : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  MainControlBar                ();

 //! Destructor
 public :
  ~MainControlBar               ();

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

#endif /* _maincontrolbar_h_*/
