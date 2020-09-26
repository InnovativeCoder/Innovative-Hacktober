namespace Brane
{
    public static partial class NumericExtensions
    {
        /// <summary>
        /// Returns the value of the bit at a given bit index of a <see cref="System.Byte"/> as a <see cref="System.Boolean"/>.
        /// </summary>
        /// <param name="number">Target <see cref="System.Byte"/> to get the bit value of.</param>
        /// <param name="bitIndex">Index of the bit to get the value of.</param>
        /// <returns>A <see cref="System.Boolean"/> represening the value of the bit at the given bit index.</returns>
        public static bool GetBit(this byte number, byte bitIndex)
        {
            const byte upperBound = ((sizeof(byte) * 8) - 1);

            if (bitIndex > upperBound) { throw new System.ArgumentException(string.Format("Bit index can not be greater than {0}", upperBound)); }

            return ((number & (((byte)(1)) << bitIndex)) != 0);
        }

        /// <summary>
        /// Returns the value of the bit at a given bit index of a <see cref="System.SByte"/> as a <see cref="System.Boolean"/>.
        /// </summary>
        /// <param name="number">Target <see cref="System.SByte"/> to get the bit value of.</param>
        /// <param name="bitIndex">Index of the bit to get the value of.</param>
        /// <returns>A <see cref="System.Boolean"/> represening the value of the bit at the given bit index.</returns>
        public static bool GetBit(this sbyte number, byte bitIndex)
        {
            const byte upperBound = ((sizeof(sbyte) * 8) - 1);

            if (bitIndex > upperBound) { throw new System.ArgumentException(string.Format("Bit index can not be greater than {0}", upperBound)); }

            return ((number & (((sbyte)(1)) << bitIndex)) != 0);
        }

        /// <summary>
        /// Returns the value of the bit at a given bit index of a <see cref="System.Int16"/> as a <see cref="System.Boolean"/>.
        /// </summary>
        /// <param name="number">Target <see cref="System.Int16"/> to get the bit value of.</param>
        /// <param name="bitIndex">Index of the bit to get the value of.</param>
        /// <returns>A <see cref="System.Boolean"/> represening the value of the bit at the given bit index.</returns>
        public static bool GetBit(this short number, byte bitIndex)
        {
            const byte upperBound = ((sizeof(short) * 8) - 1);

            if (bitIndex > upperBound) { throw new System.ArgumentException(string.Format("Bit index can not be greater than {0}", upperBound)); }

            return ((number & (((short)(1)) << bitIndex)) != 0);
        }

        /// <summary>
        /// Returns the value of the bit at a given bit index of a <see cref="System.UInt16"/> as a <see cref="System.Boolean"/>.
        /// </summary>
        /// <param name="number">Target <see cref="System.UInt16"/> to get the bit value of.</param>
        /// <param name="bitIndex">Index of the bit to get the value of.</param>
        /// <returns>A <see cref="System.Boolean"/> represening the value of the bit at the given bit index.</returns>
        public static bool GetBit(this ushort number, byte bitIndex)
        {
            const byte upperBound = ((sizeof(ushort) * 8) - 1);

            if (bitIndex > upperBound) { throw new System.ArgumentException(string.Format("Bit index can not be greater than {0}", upperBound)); }

            return ((number & (((ushort)(1)) << bitIndex)) != 0);
        }

        /// <summary>
        /// Returns the value of the bit at a given bit index of a <see cref="System.Int32"/> as a <see cref="System.Boolean"/>.
        /// </summary>
        /// <param name="number">Target <see cref="System.Int32"/> to get the bit value of.</param>
        /// <param name="bitIndex">Index of the bit to get the value of.</param>
        /// <returns>A <see cref="System.Boolean"/> represening the value of the bit at the given bit index.</returns>
        public static bool GetBit(this int number, byte bitIndex)
        {
            const byte upperBound = ((sizeof(int) * 8) - 1);

            if (bitIndex > upperBound) { throw new System.ArgumentException(string.Format("Bit index can not be greater than {0}", upperBound)); }

            return ((number & (((int)(1)) << bitIndex)) != 0);
        }

        /// <summary>
        /// Returns the value of the bit at a given bit index of a <see cref="System.UInt32"/> as a <see cref="System.Boolean"/>.
        /// </summary>
        /// <param name="number">Target <see cref="System.Int32"/> to get the bit value of.</param>
        /// <param name="bitIndex">Index of the bit to get the value of.</param>
        /// <returns>A <see cref="System.Boolean"/> represening the value of the bit at the given bit index.</returns>
        public static bool GetBit(this uint number, byte bitIndex)
        {
            const byte upperBound = ((sizeof(uint) * 8) - 1);

            if (bitIndex > upperBound) { throw new System.ArgumentException(string.Format("Bit index can not be greater than {0}", upperBound)); }

            return ((number & (((uint)(1)) << bitIndex)) != 0);
        }

        /// <summary>
        /// Returns the value of the bit at a given bit index of a <see cref="System.Int64"/> as a <see cref="System.Boolean"/>.
        /// </summary>
        /// <param name="number">Target <see cref="System.Int64"/> to get the bit value of.</param>
        /// <param name="bitIndex">Index of the bit to get the value of.</param>
        /// <returns>A <see cref="System.Boolean"/> represening the value of the bit at the given bit index.</returns>
        public static bool GetBit(this long number, byte bitIndex)
        {
            const byte upperBound = ((sizeof(long) * 8) - 1);

            if (bitIndex > upperBound) { throw new System.ArgumentException(string.Format("Bit index can not be greater than {0}", upperBound)); }

            return ((number & (((long)(1)) << bitIndex)) != 0);
        }

        /// <summary>
        /// Returns the value of the bit at a given bit index of a <see cref="System.UInt64"/> as a <see cref="System.Boolean"/>.
        /// </summary>
        /// <param name="number">Target <see cref="System.UInt64"/> to get the bit value of.</param>
        /// <param name="bitIndex">Index of the bit to get the value of.</param>
        /// <returns>A <see cref="System.Boolean"/> represening the value of the bit at the given bit index.</returns>
        public static bool GetBit(this ulong number, byte bitIndex)
        {
            const byte upperBound = ((sizeof(ulong) * 8) - 1);

            if (bitIndex > upperBound) { throw new System.ArgumentException(string.Format("Bit index can not be greater than {0}", upperBound)); }

            return ((number & (((ulong)(1)) << bitIndex)) != 0);
        }
    }
}
