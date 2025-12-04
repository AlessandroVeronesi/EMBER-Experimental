![CI (build,lint,test)] (https://github.com/AarifRahaman/EMBER-Exp/actions/workflows/ci.yml/badge.svg)

<div align="center">
<img src="doc/pictures/ember_banner_color.png"/>
</div>

---

**EMBER** is a C++ library for hardware modeling and cycle-based simulation in combination with fault simulations.

**EMBER** exposes classic RTL modeling features combined with modern use of C++ language semantics.
This allows the adopters for addressing large hardware configuration spaces without necessarily abstracting the final description.

The **EMBER** kernel is a cycle-based simulation engine that enables high-speed cycle-accurate simulations, for behavioural, RTL, and gate-level descriptions. At the same time, as C++ based, **EMBER** designs can be easily integrated with functional models, allowing for easy integration in virtual prototypes, and easy cross-abstraction simulations.

As modern technology nodes require early-stage reliability analysis, **EMBER** additionally comes with the built-in support for fault injection simulations via simulation-friendly saboteurs. We provide a small example saboteurs library including saboteurs for D-type FlipFlops, DualPort SRAMs, and a simple, small gate library. These saboteurs all contain the support for __Single-Event Upsets (SEUs)__, and __Stuck-At Faults (SA0 and SA1)__.

As **EMBER** offers an approach to simulation similar to other cycle-accurate C++ frameworks, it can also be easily integrated with other third party C++ hardware simulation tools and frameworks. An example of wrapper to integrate with Verilated designs is provided in `examples/verilator/`.

## Cite Us

If you use **EMBER** for your paper, please acknowledge our work:

```
@INPROCEEDINGS{ember,
  author={Veronesi, Alessandro and Bolzani P\"{o}hls, Leticia Maria and Favalli, Michele and Krstic, Milos and Bertozzi, Davide},
  booktitle={2025 IEEE Asian Test Symposium (ATS)}, 
  title={EMBER: A Cycle-based Framework for Early-Stage Reliability Assessment in Parametric RTL Designs}, 
  year={2025},
  volume={},
  number={},
  pages={1-6},
  keywords={Fault Injection Simulations, RTL Simulations, Reliability, Mission-Critical Systems, CAD},
  doi={}}
```

## Repository Structure

    ember/                  -- EMBER library sources
    verilator/              -- EMBER extension for simplified verilator integration
    examples/               -- Contains example projects
    saboteurs/              -- Library of EMBER saboteur components
    doc/                    -- EMBER documentation

## Compilation

**EMBER** is meant to be compiled as a static library. A `CMakeLists.txt` file is provided for a simple inclusion in more structured CMake-based projects.

**EMBER** examples can be compiled with an out-of-sources compilation, with the following commands:

    mkdir build/
    cmake .. -DBUILD_EXAMPLES=ON -DBUILD_VERILATOR=ON
    make all

Examples can be either run in block with the `make test` command, or run singularly by invoking the corresponding example executable with: `./examples<example name>/<example binary name>`.

A list of tested environements follows:

    OS:
        Ubuntu20
        Ubuntu24
    GCC:
        GCC-11
        GCC-12

## Known Issues

Current support for verilated components is partial as Verilator 4.x presents inconsistent behaviours when driving internal signals. This cause an unpredictable behaviour of **EMBER** saboteurs for verilated components.
Driving internal signals is highly simplified from Verilator 5.x and further, however newer versions of Verilator are currently untested.

## Credits

We thank [Giovanni Veronesi](https://www.instagram.com/giovanissimogiovanni/) for the EMBER logo and graphics (available in the `doc/pictures` folder).
