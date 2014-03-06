using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sannel.EcoSystem.Interfaces
{
	public interface IEcoEngine : IDisposable
	{
		void AddLifeSpawner(ILifeSpawner spawner);

		void AddTerrainSpawner(ITerrainSpawner spawner);

		void GenerateMap();

		void GenerateLife();

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
