using System;
using System.Collections.Generic;
using System.Linq;
#if NETFX_CORE || WINDOWS_PHONE
using System.Threading.Tasks;
#endif
using System.Text;

namespace Sannel.EcoSystem.Base
{
	public abstract class Engine
	{
		protected Terrain[,] terrain;

		public int Rows
		{
			get;
			private set;
		}

		public int Columns
		{
			get;
			private set;
		}

		Engine(int rows, int columns)
		{
			Rows = rows;
			Columns = columns;
			terrain = new Terrain[rows, columns];
		}

		public virtual void Generate()
		{

		}

		public virtual void Tick()
		{
		}

		#region Protected
		/// <summary>
		/// Returns a list of Precentages used to generate the terrain 
		/// </summary>
		/// <returns></returns>
		protected virtual IList<Precentages> GetGenerationPrecentages(out uint maxPrecentage)
		{
			IList<Precentages> list = new List<Precentages>();
			list.Add(new Precentages
			{
				Min=0,
				Max=1000,
				GenerationShape = GenerationShape.OneTile,
				Water = 64,
				WaterQuality = byte.MaxValue
			});
			list.Add(new Precentages
				{
					Min=1000,
					Max=1020,
					GenerationShape = GenerationShape.Circule,
					Water = 255,
					WaterQuality = 255,
					MinSize = 2,
					MaxSize = 4
				});
			maxPrecentage = 1020;
			return list;
		}
		#endregion

#if NETFX_CORE || WINDOWS_PHONE
		public virtual Task GenerateAsync()
		{
			return Task.Run(() => { Generate(); });
		}
#endif
	}
}
