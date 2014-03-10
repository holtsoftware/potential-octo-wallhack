using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sannel.EcoSystem.Interfaces
{
	public interface IEcoEngine : IDisposable
	{
		void AddTerrainSpawner(ITerrainSpawner spawner);

		/// <summary>
		/// Generates the maps given the provided TerrainSpawners
		/// </summary>
		void GenerateMap();

		/// <summary>
		/// Called to indicate an engin tick thats sent to all terrain and life.
		/// </summary>
		void Tick();

		ITerrain GetTerrainAt(int row, int column);

		ILife GetLifeAt(int row, int column);

		int Columns
		{
			get;
		}

		int Rows
		{
			get;
		}
	}
}
