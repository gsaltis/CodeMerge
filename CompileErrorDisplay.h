/*****************************************************************************
 * FILE NAME    : CompileErrorDisplay.h
 * DATE         : December 04 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _compileerrordisplay_h_
#define _compileerrordisplay_h_

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
#define COMPILE_ERROR_DISPLAY_X         200
#define COMPILE_ERROR_DISPLAY_Y         200
#define COMPILE_ERROR_DISPLAY_WIDTH     200
#define COMPILE_ERROR_DISPLAY_HEIGHT    200

/*****************************************************************************!
 * Exported Class : CompileErrorDisplay
 *****************************************************************************/
class CompileErrorDisplay : public QTextEdit
{
  Q_OBJECT;

 //! Constructors
 public :
  CompileErrorDisplay           ();

 //! Destructor
 public :
  ~CompileErrorDisplay          ();

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

 //! Private Data
 private :
  QColor                        BackgroundColor;
  QColor                        TextColor;

 //! Public Slots
 public slots :
  void                          SlotErrorMessage        (QString InErrorMessage);

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _compileerrordisplay_h_*/
