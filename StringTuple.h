/*****************************************************************************
 * FILE NAME    : StringTuple.h
 * DATE         : December 01 2023
 * PROJECT      : 
 * COPYRIGHT    : Copyright (C) 2023 by Gregory R Saltis
 *****************************************************************************/
#ifndef _stringtuple_h_
#define _stringtuple_h_

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

/*****************************************************************************!
 * Exported Class : StringTuple
 *****************************************************************************/
class StringTuple : public QWidget
{
  Q_OBJECT;

 //! Constructors
 public :
  StringTuple                   ();
  StringTuple                   (QString InString1, QString InString2);

 //! Destructor
 public :
  ~StringTuple                  ();

 //! Public Methods
 public :
  QString                       GetString1              (void);
  void                          SetString1              (QString InString1);
  QString                       GetString2              (void);
  void                          SetString2              (QString InString2);
  int                           Compare                 (StringTuple InTuple);

 //! Public Data
 public :

 //! Protected Methods
 protected :

 //! Protected Data
 protected :

 //! Private Methods
 private :

 //! Private Data
 private :
  QString                       string1;
  QString                       string2;

};

#endif /* _stringtuple_h_*/
