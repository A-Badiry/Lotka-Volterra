# Hare-Fox Population Calculator

This small project implements the Lotka-Volterra model to calculate the population dynamics of Hares and Foxes based on user-input parameters. The model is a classic predator-prey system that simulates the interactions between the two species over time.

1. **Predator-Prey Model:**
   - Lotka-Volterra equations describe a simple predator-prey model. Here's how they are represented:

    $$
    \frac{dx}{dt} = \alpha x - \beta xy
    $$
    
    $$
    \frac{dy}{dt} = \delta xy - \gamma y
    $$



   - Here, \(x\) represents the population of Hares, and \(y\) represents the population of Foxes. Adjust the parameters \(\alpha\), \(\beta\), \(\delta\), and \(\gamma\) based on your specific equations.

2. **Equations with Explanation:**
   - You can also include equations with a brief explanation:

   ```markdown
   The Lotka-Volterra equations for a predator-prey model are given by:

   \[
   \frac{dx}{dt} = \alpha x - \beta xy
   \]

   \[
   \frac{dy}{dt} = \delta xy - \gamma y
   \]

   Where:
   - \(x\) is the population of Hares,
   - \(y\) is the population of Foxes,
   - \(\alpha\) represents the birth rate of Hares,
   - \(\beta\) represents the predation rate,
   - \(\delta\) represents the rate of successful predation,
   - \(\gamma\) represents the death rate of Foxes.
   ```

   Adjust the parameters and explanations based on your specific context.

Ensure your README.md file is rendered on a platform that supports MathJax or LaTeX rendering for math equations. GitHub, for example, supports LaTeX-style math rendering in Markdown files.

## How to Use

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/A-Badiry/Lotka-Volterra
   cd Lotka-Volterra
   ```

2. **Compile and Run the Program:**
   ```bash
   make
   ./Model
   ```

3. **Input Parameters:**
   - Enter the initial population of Hares (INTEGER).
   - Enter the initial population of Foxes (INTEGER).
   - Enter the number of days for which to track the populations (INTEGER).

   - Set the birth rate of Hares (alpha - DOUBLE).
   - Set the effect of predators on prey (beta - DOUBLE).
   - Set the effect of prey on predators (delta - DOUBLE)
   - Set the death rate of Foxes (gamma - DOUBLE).

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