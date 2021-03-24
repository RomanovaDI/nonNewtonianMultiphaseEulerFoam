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

\*---------------------------------------------------------------------------*/

#include "singlePhaseTransportViscosityModel.H"
#include "viscosityModel.H"
#include "volFields.H"

// * * * * * * * * * * * * * * Static Data Members * * * * * * * * * * * * * //

namespace Foam
{
    defineTypeNameAndDebug(singlePhaseTransportViscosityModel, 0);
}


// * * * * * * * * * * * * * * * * Constructors  * * * * * * * * * * * * * * //

Foam::singlePhaseTransportViscosityModel::singlePhaseTransportViscosityModel
(
    const volVectorField& U,
    const surfaceScalarField& phi,
    const dictionary& phaseDict
)
:
    phaseDict_(phaseDict),
    viscosityModelPtr_(viscosityModel::New("nu", phaseDict_, U, phi))
{}


// * * * * * * * * * * * * * * * * Destructor  * * * * * * * * * * * * * * * //

Foam::singlePhaseTransportViscosityModel::~singlePhaseTransportViscosityModel()
{}


// * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * * //

Foam::tmp<Foam::volScalarField>
Foam::singlePhaseTransportViscosityModel::nu() const
{
    return viscosityModelPtr_->nu();
}


Foam::tmp<Foam::scalarField>
Foam::singlePhaseTransportViscosityModel::nu(const label patchi) const
{
    return viscosityModelPtr_->nu(patchi);
}


void Foam::singlePhaseTransportViscosityModel::correct()
{
    viscosityModelPtr_->correct();
}


bool Foam::singlePhaseTransportViscosityModel::read()
{
	return viscosityModelPtr_->read(phaseDict_);
}


// ************************************************************************* //
