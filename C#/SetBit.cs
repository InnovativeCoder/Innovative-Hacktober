namespace Brane
{
    public static partial class NumericExtensions
    {
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

            return ((int)(bitValue ? (number | (1 << bitIndex)) : (number & ~(1 << bitIndex))));
        }
    }
}
