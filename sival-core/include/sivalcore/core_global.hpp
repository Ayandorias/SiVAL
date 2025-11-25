#pragma once



/*! \page sival_core SiVAL Core Framework (sival-core)
 *
 * \section intro_sec Introduction
 *
 * sival-core is the non-visual C++/Qt framework that provides
 * fundamental infrastructure for application development.
 * It establishes a clear architectural pattern for data modeling
 * and persistence, and provides a set of essential,
 * reusable application services.
 *
 * The library is designed to enforce the principles of
 * loose coupling and the Single Responsibility Principle (SRP).
 *
 * \section arch_sec Core Architecture: Model-Handler Decoupling
 *
 * The core architecture is based on the **Strategy** design pattern to
 * strictly decouple the data models (the *state*) from the persistence
 * layer (the *I/O logic*).
 *
 * This decoupling is achieved through two fundamental abstract base classes:
 *
 * \subsection arch_model SivalDocumentModel (The Model Abstraction)
 *
 * The `SivalDocumentModel` class (derived from `QObject`) serves as the
 * abstract base for all data-centric objects. It is the
 * "Single Source of Truth" for the application state.
 *
 * Its responsibilities include:
 * - **State Management:** Owning the data in memory and
 * managing the modification status (e.g., `isModified()`).
 * - **Signal Emission:** Notifying consumers of state changes
 * (via Qt Signals).
 * - **I/O Delegation:** It holds a reference to an
 * `ISivalIoHandler` interface, to which all load and
 * save operations are delegated.
 *
 * \subsection arch_handler ISivalIoHandler (The Persistence Abstraction)
 *
 * The `ISivalIoHandler` interface defines the "contract" for all
 * persistence logic.
 *
 * Its responsibilities include:
 * - **API Definition:** It declares the abstract `load()` and `save()`
 * methods.
 * - **Statelessness:** A handler is a stateless "translator".
 * It does not own any data itself.
 * - **Specialization:** Concrete implementations (e.g., `SivalDriverIo`)
 * are specialized to parse a data source (e.g., a JSON file)
 * and (de)serialize a compatible `SivalDocumentModel`.
 *
 * \section framework_components Framework Components
 *
 * sival-core provides both the abstract architectural layers and
 * a set of concrete, ready-to-use implementations.
 *
 * \subsection comp_models Concrete Models
 * Pre-defined classes derived from `SivalDocumentModel` for
 * common use cases:
 * - **SivalSettings:** A generic model for managing
 * application settings (often implemented internally as a key-value tree/QVariantMap).
 * - **SivalDriverParameters:** A type-safe domain model for encapsulating
 * driver (T/S) parameters.
 * - **SivalMeasurementData:** A model for storing
 * measurement data series (e.g., frequency response, impedance).
 * - **SivalProject / SivalWorkspace:** Models for managing
 * hierarchical document structures.
 *
 * \subsection comp_handlers Concrete Handlers
 * A collection of `ISivalIoHandler` implementations, specialized for
 * the pre-defined models and their respective file formats:
 * - **SivalDriverIo:** (De)serializes `SivalDriverParameters` from/to
 * JSON files.
 * - **SivalImpedanceZmaIo:** (De)serializes `SivalMeasurementData`
 * from/to .zma text files.
 * - **SivalSettingsIo:** (De)serializes `SivalSettings` from/to
 * generic configuration files (e..g., JSON).
 *
 * \subsection comp_services Core Services
 * Application-agnostic services, typically implemented as singletons or
 * static facades:
 * - **SivalLog:** A static facade for an extensible logging system
 * (based on the `ILogSink` interface).
 * - **UpdateService:** An asynchronous `QObject`-based service for
 * checking for software updates over a network.
 */




#include <QtCore/qglobal.h>

#if defined(SIVAL_CORE_LIBRARY)
#define SIVAL_CORE_EXPORT Q_DECL_EXPORT
#else
#define SIVAL_CORE_EXPORT Q_DECL_IMPORT
#endif



