/*****************************************************************************
 * FILE NAME    : MainWindowHeader.h
 * DATE         : November 29 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _mainwindowheader_h_
#define _mainwindowheader_h_

/*****************************************************************************!
 * Global Headers
 *****************************************************************************/
#include <QtCore>
#include <QtGui>
#include <QWidget>
#include <QLabel>

/*****************************************************************************!
 * Local Headers
 *****************************************************************************/

/*****************************************************************************!
 * Exported Macros
 *****************************************************************************/
#define MAIN_WINDOW_HEADER_X            200
#define MAIN_WINDOW_HEADER_Y            200
#define MAIN_WINDOW_HEADER_WIDTH        200
#define MAIN_WINDOW_HEADER_HEIGHT       20

/*****************************************************************************!
 * Exported Class : MainWindowHeader
 *****************************************************************************/
class MainWindowHeader : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  MainWindowHeader              (QString InText, QWidget* InParent);

 //! Destructor
 public :
  ~MainWindowHeader             ();

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
  void                          paintEvent              (QPaintEvent* InEvent);

 //! Private Data
 private :
  QColor                        StartingColor;
  QColor                        EndingColor;
  QLabel*                       TextLabel;
  QString                       text;

 //! Public Slots
 public slots :

 //! Public Signals
 signals :

 //! Public Actions
 public :

};

#endif /* _mainwindowheader_h_*/
