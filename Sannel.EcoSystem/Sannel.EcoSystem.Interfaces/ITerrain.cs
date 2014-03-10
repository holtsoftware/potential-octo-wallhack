﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sannel.EcoSystem.Interfaces
{
	public interface ITerrain : IDisposable
	{
		byte Water
		{
			get;
		}

		byte WaterQuality
		{
			get;
		}

		byte Sun
		{
			get;
			set;
		}

		Uri ImageFile
		{
			get;
		}

		ITerrainSpawner Spawner
		{
			get;
		}

		/// <summary>
		/// A tick coming from the engine not much for terrain to do here.
		/// </summary>
		void Tick();
	}
}
