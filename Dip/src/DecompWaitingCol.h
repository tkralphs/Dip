//===========================================================================//
// This file is part of the DIP Solver Framework.                            //
//                                                                           //
// DIP is distributed under the Eclipse Public License as part of the        //
// COIN-OR repository (http://www.coin-or.org).                              //
//                                                                           //
// Authors: Matthew Galati, SAS Institute Inc. (matthew.galati@sas.com)      //
//          Ted Ralphs, Lehigh University (ted@lehigh.edu)                   //
//          Jiadong Wang, Lehigh University (jiw408@lehigh.edu)              //
//                                                                           //
// Copyright (C) 2002-2019, Lehigh University, Matthew Galati, Ted Ralphs    //
// All Rights Reserved.                                                      //
//===========================================================================//

#ifndef DECOMP_WAITING_COL_INCLUDE
#define DECOMP_WAITING_COL_INCLUDE

#include "Decomp.h"
#include "DecompVar.h"
#include "UtilMacros.h"

// ---------------------------------------------------------------------- //
class DecompWaitingCol {

private:
   DecompVar*         m_var;  //s        the variable
   CoinPackedVector* m_col;   //(A'' s)  the column

public:
   inline DecompVar*         getVarPtr() const {
      return m_var;
   }
   inline CoinPackedVector* getColPtr() const {
      return m_col;
   }
   inline const double getReducedCost() const  {
      return m_var->getReducedCost();
   }
   inline const double getLowerBound() const   {
      return m_var->getLowerBound();
   }
   inline const double getUpperBound() const   {
      return m_var->getUpperBound();
   }
   inline const double getOrigCost() const     {
      return m_var->getOriginalCost();
   }

   inline void   deleteCol() {
      UTIL_DELPTR(m_col);
   }
   inline void   deleteVar() {
      UTIL_DELPTR(m_var);
   }
   inline void   clearVar()  {
      m_var = 0;
   }
   inline void   setCol(CoinPackedVector* col) {
      m_col = col;
   }

   bool setReducedCost(const double*       u,
                       const DecompStatus    stat);

public:
   DecompWaitingCol(const DecompWaitingCol& rhs) {
      m_var = rhs.m_var;
      m_col = rhs.m_col;
   }
   DecompWaitingCol(DecompVar* var, CoinPackedVector* col) :
      m_var(var),
      m_col(col) {}

   ~DecompWaitingCol() {}
};

#endif
