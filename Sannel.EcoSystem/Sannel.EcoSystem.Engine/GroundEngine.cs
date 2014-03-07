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
			if (spawner == null)
			{
				throw new ArgumentNullException("spawner");
			}

			spawners.Add(spawner);
		}

		public void AddTerrainSpawner(ITerrainSpawner spawner)
		{
			if (terrain == null)
			{
				throw new ArgumentNullException("spawner");
			}

			tspawners.Add(spawner);
		}

		private void square(int row, int col, byte size, ITerrainSpawner spawner)
		{
			for (int r = row - size; r < row + size; r++)
			{
				for (int c = col - size; c < col + size; c++)
				{
					if (c >= 0 && c < terrain.Columns)
					{
						if (r >= 0 && r < terrain.Rows)
						{
							if (terrain[r, c] != null)
							{
								terrain[r, c].Dispose();
							}

							terrain[r, c] = spawner.Create();
						}
					}
				}
			}
		}

		public void GenerateMap()
		{
			Random rand = new Random();

			for (int c = 0; c < terrain.Columns; c++)
			{
				for (int r = 0; r < terrain.Rows; r++)
				{
					if (terrain[r, c] == null)
					{
						bool found = false;
						while (!found)
						{
							float val = (float)rand.NextDouble();
							var index = rand.Next(0, tspawners.Count);
							var spawner = tspawners[index];
							if (spawner.GenerationPrecentage > val)
							{
								found = true;
								switch (spawner.Shape)
								{
									case GenerationShape.OneTile:
										terrain[r, c] = spawner.Create();
										break;

									case GenerationShape.Square:
										square(r, c, spawner.ShapeSize, spawner);
										break;
								}
							}
						}
					}
					//var val = rand.Next(0, top);

					//foreach(var p in pres)
					//{
					//	if(val >= p.Min && val <= p.Max)
					//	{
					//		terrain[r, c] = p.Spawner.Create();
					//		break;
					//	}
					//}
				}
			}
		}

		public void GenerateLife()
		{
		}

		public void Dispose()
		{
			foreach (var s in spawners)
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
