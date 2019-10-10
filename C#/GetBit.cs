namespace Brane
{
    public static partial class NumericExtensions
    {
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

            return ((number & (1 << bitIndex)) != 0);
        }
    }
}
