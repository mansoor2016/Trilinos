//@HEADER
// ************************************************************************
//
//          Trilinos: An Object-Oriented Solver Framework
//              Copyright (2001) Sandia Corporation
//
// Under terms of Contract DE-AC04-94AL85000, there is a non-exclusive
// license for use of this work by or on behalf of the U.S. Government.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2, or (at your option)
// any later version.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//
// Questions? Contact Michael A. Heroux (maherou@sandia.gov)
//
// ************************************************************************
//@HEADER
                                                                                                   
#ifndef EpetraExt_CRSMATRIX_SOLVERMAP_H
#define EpetraExt_CRSMATRIX_SOLVERMAP_H

#include <EpetraExt_Transform.h>

class Epetra_CrsMatrix;
class Epetra_CrsGraph;
class Epetra_Map;

namespace EpetraExt {

///
/** Given an input Epetra_CrsMatrix, the column map is checked for missing indices associated
 *  with the local rows.  If found, a view of the Epetra_CrsMatrix is formed using a new
 *  Epetra_CrsGraph with a fixed column mapping including all local row indices.
 */
class CrsMatrix_SolverMap : public StructuralSameTypeTransform<Epetra_CrsMatrix> {

  Epetra_Map * NewColMap_;
  Epetra_CrsGraph * NewGraph_;

 public:

  ///
  /** Destructor
   */
  ~CrsMatrix_SolverMap();

  ///
  /** Constructor
   */
  CrsMatrix_SolverMap()
  : NewColMap_(0),
    NewGraph_(0)
  {}

  ///
  /** Constructs fixed view of Epetra_CrsMatrix as necessary.
   */
  NewTypeRef operator()( OriginalTypeRef orig );

};

} //namespace EpetraExt

#endif //EpetraExt_CRSMATRIX_SOLVERMAP_H
