class Solution:
    def convertTemperature(self, celsius: float) -> List[float]:
        kelvin = celsius + 273.15
        faren = 1.8 * celsius + 32
        return [kelvin, faren]
        