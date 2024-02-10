# Hare-Fox Population Calculator

This small project implements the Lotka-Volterra model to calculate the population dynamics of Hares and Foxes based on user-input parameters. The model is a classic predator-prey system that simulates the interactions between the two species over time.

## How to Use

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/A-Badiry/Lotka-Volterra
   cd Lotka-Volterra
   ```

2. **Run the Program:**
   ```bash
   make
   ```

3. **Input Parameters:**
   - Enter the initial population of Hares.
   - Enter the initial population of Foxes.
   - Enter the number of days for which to track the populations

   - Set the birth rate of Hares (alpha).
   - Set the effect of predators on prey (beta).
   - Set the effect of prey on predators (delta)
   - Set the death rate of Foxes (gamma).

4. **View Results:**
   The program will simulate the population dynamics over time using the Lotka-Volterra model and display the results using the "gnuplot" and "Qt" as the terminal output.

## Example

```bash
Enter the initial population of Hares: 100
Enter the initial population of Foxes: 40
Enter the number of days for which to track the populations: 100

Set the birth rate of Hares (alpha): 1.2
Set the effect of predators on prey (beta): 0.01
Set the effect of prey on predators (delta): 0.01
Set the death rate of Foxes (gamma): 0.5
```

## Dependencies

- GNUplot graphing utility.
- Qt Framework.

## License

This project is licensed under [the GNU General Public license](https://www.gnu.org/licenses/gpl-3.0.html)

Feel free to report any issues at achraf.badiry@edu.bme.hu