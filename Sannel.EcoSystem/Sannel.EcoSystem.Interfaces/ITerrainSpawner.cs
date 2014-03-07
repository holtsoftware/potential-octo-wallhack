﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sannel.EcoSystem.Interfaces
{
	public interface ITerrainSpawner : ISpawner
	{
		Uri ImageFile
		{
			get;
			set;
		}

		GenerationShape Shape
		{
			get;
		}

		byte ShapeSize
		{
			get;
		}

		ITerrain Create();
	}
}