namespace Brane
{
    public static partial class NumericExtensions
    {
        /// <summary>
        /// Sets the value of the bit at a given bit index of a <see cref="System.Byte"/>
        /// </summary>
        /// <param name="number">Target <see cref="System.Byte"/> to change the bit value of.</param>
        /// <param name="bitIndex">Index of the bit to set the value of.</param>
        /// <param name="bitValue">Target bit's value.</param>
        /// <returns>A new <see cref="System.Byte"/> with the changed bit.</returns>
        public static byte SetBit(this byte number, byte bitIndex, bool bitValue)
        {
            const byte upperBound = ((sizeof(byte) * 8) - 1);

            if (bitIndex > upperBound) { throw new System.ArgumentException(string.Format("Bit index can not be greater than {0}", upperBound)); }

            return ((byte)(bitValue ? (number | (((byte)(1)) << bitIndex)) : (number & ~(((byte)(1)) << bitIndex))));
        }

        /// <summary>
        /// Sets the value of the bit at a given bit index of a <see cref="System.Sbyte"/>
        /// </summary>
        /// <param name="number">Target <see cref="System.Sbyte"/> to change the bit value of.</param>
        /// <param name="bitIndex">Index of the bit to set the value of.</param>
        /// <param name="bitValue">Target bit's value.</param>
        /// <returns>A new <see cref="System.Sbyte"/> with the changed bit.</returns>
        public static sbyte SetBit(this sbyte number, byte bitIndex, bool bitValue)
        {
            const byte upperBound = ((sizeof(sbyte) * 8) - 1);

            if (bitIndex > upperBound) { throw new System.ArgumentException(string.Format("Bit index can not be greater than {0}", upperBound)); }

            return ((sbyte)(bitValue ? (number | (((sbyte)(1)) << bitIndex)) : (number & ~(((sbyte)(1)) << bitIndex))));
        }

        /// <summary>
        /// Sets the value of the bit at a given bit index of a <see cref="System.Int16"/>
        /// </summary>
        /// <param name="number">Target <see cref="System.Int16"/> to change the bit value of.</param>
        /// <param name="bitIndex">Index of the bit to set the value of.</param>
        /// <param name="bitValue">Target bit's value.</param>
        /// <returns>A new <see cref="System.Int16"/> with the changed bit.</returns>
        public static short SetBit(this short number, byte bitIndex, bool bitValue)
        {
            const byte upperBound = ((sizeof(short) * 8) - 1);

            if (bitIndex > upperBound) { throw new System.ArgumentException(string.Format("Bit index can not be greater than {0}", upperBound)); }

            return ((short)(bitValue ? (number | (((short)(1)) << bitIndex)) : (number & ~(((short)(1)) << bitIndex))));
        }

        /// <summary>
        /// Sets the value of the bit at a given bit index of a <see cref="System.UInt16"/>
        /// </summary>
        /// <param name="number">Target <see cref="System.UInt16"/> to change the bit value of.</param>
        /// <param name="bitIndex">Index of the bit to set the value of.</param>
        /// <param name="bitValue">Target bit's value.</param>
        /// <returns>A new <see cref="System.UInt16"/> with the changed bit.</returns>
        public static ushort SetBit(this ushort number, byte bitIndex, bool bitValue)
        {
            const byte upperBound = ((sizeof(ushort) * 8) - 1);

            if (bitIndex > upperBound) { throw new System.ArgumentException(string.Format("Bit index can not be greater than {0}", upperBound)); }

            return ((ushort)(bitValue ? (number | (((ushort)(1)) << bitIndex)) : (number & ~(((ushort)(1)) << bitIndex))));
        }

        /// <summary>
        /// Sets the value of the bit at a given bit index of a <see cref="System.Int32"/>
        /// </summary>
        /// <param name="number">Target <see cref="System.Int32"/> to change the bit value of.</param>
        /// <param name="bitIndex">Index of the bit to set the value of.</param>
        /// <param name="bitValue">Target bit's value.</param>
        /// <returns>A new <see cref="System.Int32"/> with the changed bit.</returns>
        public static int SetBit(this int number, byte bitIndex, bool bitValue)
        {
            const byte upperBound = ((sizeof(int) * 8) - 1);

            if (bitIndex > upperBound) { throw new System.ArgumentException(string.Format("Bit index can not be greater than {0}", upperBound)); }

            return ((int)(bitValue ? (number | (((int)(1)) << bitIndex)) : (number & ~(((int)(1)) << bitIndex))));
        }

        /// <summary>
        /// Sets the value of the bit at a given bit index of a <see cref="System.UInt32"/>
        /// </summary>
        /// <param name="number">Target <see cref="System.UInt32"/> to change the bit value of.</param>
        /// <param name="bitIndex">Index of the bit to set the value of.</param>
        /// <param name="bitValue">Target bit's value.</param>
        /// <returns>A new <see cref="System.UInt32"/> with the changed bit.</returns>
        public static uint SetBit(this uint number, byte bitIndex, bool bitValue)
        {
            const byte upperBound = ((sizeof(uint) * 8) - 1);

            if (bitIndex > upperBound) { throw new System.ArgumentException(string.Format("Bit index can not be greater than {0}", upperBound)); }

            return ((uint)(bitValue ? (number | (((uint)(1)) << bitIndex)) : (number & ~(((uint)(1)) << bitIndex))));
        }

        /// <summary>
        /// Sets the value of the bit at a given bit index of a <see cref="System.Int64"/>
        /// </summary>
        /// <param name="number">Target <see cref="System.Int64"/> to change the bit value of.</param>
        /// <param name="bitIndex">Index of the bit to set the value of.</param>
        /// <param name="bitValue">Target bit's value.</param>
        /// <returns>A new <see cref="System.Int64"/> with the changed bit.</returns>
        public static long SetBit(this long number, byte bitIndex, bool bitValue)
        {
            const byte upperBound = ((sizeof(long) * 8) - 1);

            if (bitIndex > upperBound) { throw new System.ArgumentException(string.Format("Bit index can not be greater than {0}", upperBound)); }

            return ((long)(bitValue ? (number | (((long)(1)) << bitIndex)) : (number & ~(((long)(1)) << bitIndex))));
        }

        /// <summary>
        /// Sets the value of the bit at a given bit index of a <see cref="System.UInt64"/>
        /// </summary>
        /// <param name="number">Target <see cref="System.UInt64"/> to change the bit value of.</param>
        /// <param name="bitIndex">Index of the bit to set the value of.</param>
        /// <param name="bitValue">Target bit's value.</param>
        /// <returns>A new <see cref="System.UInt64"/> with the changed bit.</returns>
        public static ulong SetBit(this ulong number, byte bitIndex, bool bitValue)
        {
            const byte upperBound = ((sizeof(ulong) * 8) - 1);

            if (bitIndex > upperBound) { throw new System.ArgumentException(string.Format("Bit index can not be greater than {0}", upperBound)); }

            return ((ulong)(bitValue ? (number | (((ulong)(1)) << bitIndex)) : (number & ~(((ulong)(1)) << bitIndex))));
        }
    }
}
