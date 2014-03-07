using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sannel.EcoSystem.Interfaces
{
	public interface ILifeSpawner : ISpawner
	{
		/// <summary>
		/// Weather or not this spawner can spawn on this type of terrain.
		/// </summary>
		/// <param name="terrain">The terrain the engin is trying to spawn this on.</param>
		/// <returns>true to let the engine know you can create a type of this spawner</returns>
		bool CanSpawnOn(ITerrain terrain);
	}
}
