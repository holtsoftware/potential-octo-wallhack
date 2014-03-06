using Sannel.Collections.Generic;
using Sannel.EcoSystem.Interfaces;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Sannel.EcoSystem.Engine
{
	public class GroundEngine : IEcoEngine
	{
		#region Privates
		private IList<ILifeSpawner> spawners = new List<ILifeSpawner>();
		private IList<ITerrainSpawner> tspawners = new List<ITerrainSpawner>();
		private IMatrix<ITerrain> terrain;
		private IMatrix<ILife> life;
		#endregion

		public GroundEngine(int rows, int columns)
		{
			terrain = new Matrix<ITerrain>(rows, columns);
			life = new Matrix<ILife>(rows, columns);
		}

		public void AddLifeSpawner(ILifeSpawner spawner)
		{
			if(spawner == null)
			{
				throw new ArgumentNullException("spawner");
			}

			spawners.Add(spawner);
		}

		public void AddTerrainSpawner(ITerrainSpawner spawner)
		{
			if(terrain == null)
			{
				throw new ArgumentNullException("spawner");
			}

			tspawners.Add(spawner);
		}

		public void GenerateMap()
		{
			List<Presentage> pres = new List<Presentage>();
			int top = 0;
			foreach(var spawner in tspawners)
			{
				Presentage p = new Presentage();
				p.Min = top;
				p.Max = top + (int)spawner.GeneratePrecentage;
				top = p.Max + 1;
				p.Spawner = spawner;
				pres.Add(p);
			}

			top--;

			Random rand = new Random();

			for(int c=0; c < terrain.Columns;c++)
			{
				for(int r=0;r<terrain.Rows;r++)
				{
					var val = rand.Next(0, top);

					foreach(var p in pres)
					{
						if(val >= p.Min && val <= p.Max)
						{
							terrain[r, c] = p.Spawner.Create();
							break;
						}
					}
				}
			}
		}

		public void GenerateLife()
		{
		}

		public void Dispose()
		{
			foreach(var s in spawners)
			{
				s.Dispose();
			}
		}


		public int Columns
		{
			get { return terrain.Columns; }
		}

		public int Rows
		{
			get { return terrain.Rows; }
		}


		public ITerrain GetTerrainAt(int row, int column)
		{
			return terrain[row, column];
		}

		public ILife GetLifeAt(int row, int column)
		{
			throw new NotImplementedException();
		}
	}
}
