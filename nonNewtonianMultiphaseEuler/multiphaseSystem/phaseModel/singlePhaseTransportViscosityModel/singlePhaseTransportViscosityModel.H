/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     |
    \\  /    A nd           | www.openfoam.com
     \\/     M anipulation  |
-------------------------------------------------------------------------------
    Copyright (C) 2011-2016 OpenFOAM Foundation
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Class
    Foam::singlePhaseTransportViscosityModel

Description
    A simple single-phase transport model based on viscosityModel.

    Used by the incompressible single-phase solvers like simpleFoam,
    pimpleFoam etc.

SourceFiles
    singlePhaseTransportViscosityModel.C

\*---------------------------------------------------------------------------*/

#ifndef singlePhaseTransportViscosityModel_H
#define singlePhaseTransportViscosityModel_H

#include "incompressible/transportModel/transportModel.H"
#include "IOdictionary.H"
#include "autoPtr.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

class viscosityModel;

/*---------------------------------------------------------------------------*\
                Class singlePhaseTransportModel Declaration
\*---------------------------------------------------------------------------*/

class singlePhaseTransportViscosityModel
:
    public transportModel
{
    // Private Data
        dictionary phaseDict_;

        autoPtr<viscosityModel> viscosityModelPtr_;


    // Private Member Functions

        //- No copy construct
        singlePhaseTransportViscosityModel(const singlePhaseTransportViscosityModel&) = delete;

        //- No copy assignment
        void operator=(const singlePhaseTransportViscosityModel&) = delete;


public:

    //- Runtime type information
    TypeName("singlePhaseTransportViscosityModel");


    // Constructors

        //- Construct from components
        singlePhaseTransportViscosityModel
        (
            const volVectorField& U,
            const surfaceScalarField& phi,
		    const dictionary& phaseDict
        );


    //- Destructor
    virtual ~singlePhaseTransportViscosityModel();


    // Member Functions

        //- Return the laminar viscosity
        virtual tmp<volScalarField> nu() const;

        //- Return the laminar viscosity for patch
        virtual tmp<scalarField> nu(const label patchi) const;

        //- Correct the laminar viscosity
        virtual void correct();

        //- Read transportProperties dictionary
        virtual bool read();
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
