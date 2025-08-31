# C++ Expense Tracker with Flask Web Interface

A comprehensive personal expense tracking system built with C++ core architecture and a modern Flask-based web interface. This dual-interface application provides both command-line and browser-based access for managing personal finances with enterprise-grade security and data persistence.

## Architecture Overview

The project implements a hybrid architecture combining the performance and reliability of C++ for core business logic with the accessibility of a modern web interface. The system features modular design principles, file-based data persistence, and robust security through SHA-256 password hashing.

### Core Technologies
- **Backend**: C++17 with STL
- **Web Interface**: Flask (Python 3.10+)
- **Security**: SHA-256 hashing via picosha2 library
- **Data Storage**: CSV-based file system
- **Build System**: GNU Make with multi-architecture support
- **Containerization**: Docker with multi-stage builds

## Project Structure

```
expense-tracker/
├── src/                    # C++ source implementation
│   ├── main.cpp           # Application entry point
│   ├── Expense.cpp        # Expense data model
│   ├── ExpenseManager.cpp # Core business logic
│   ├── FileHandler.cpp    # File I/O operations
│   ├── Menu.cpp           # CLI interface
│   └── PasswordManager.cpp # Authentication system
├── include/               # C++ header files
│   ├── Expense.h
│   ├── ExpenseManager.h
│   ├── FileHandler.h
│   ├── Menu.h
│   ├── PasswordManager.h
│   └── picosha2/          # SHA-256 library
├── web/                   # Flask web application
│   ├── app.py            # Flask application server
│   ├── templates/        # Jinja2 HTML templates
│   │   ├── index.html    # Main dashboard
│   │   └── edit.html     # Edit form interface
│   └── static/           # CSS and assets
├── data/                  # Application data store
│   ├── expenses.csv      # Expense records
│   └── password.txt      # Hashed password
├── build/                 # Compiled binaries
├── reports/              # Generated expense reports
├── Dockerfile.cli        # CLI container definition
├── Dockerfile.web        # Web container definition
├── docker-compose.yml    # Multi-service orchestration
├── makefile              # Build automation
└── requirements.txt      # Python dependencies
```

## Feature Set

### Command Line Interface
- Interactive menu-driven expense management
- Secure password-protected access with SHA-256 hashing
- Real-time expense entry with data validation
- Comprehensive reporting and analytics
- Category-based expense filtering
- Monthly summary generation with budget warnings
- Advanced search functionality across all expense fields
- Export capabilities for monthly reports

### Web Interface
- Modern, responsive dashboard design
- Dark/light theme toggle with system preference detection
- Real-time expense addition and editing
- Interactive table with inline actions
- Mobile-optimized responsive layout
- Bootstrap-powered UI components
- Animated transitions and visual feedback

### Data Management
- CSV-based persistence for platform independence
- Thread-safe file operations
- Data integrity validation
- Automatic backup and recovery mechanisms
- Cross-platform compatibility

### Security Features
- SHA-256 password hashing with picosha2 library
- Secure password input masking
- File-based authentication persistence
- Access control for sensitive operations

## Quick Start

### Prerequisites
- GCC 7.0+ with C++17 support
- Python 3.10 or higher
- Make build system
- Git (for cloning)

### Building the CLI Application

```bash
# Clone the repository
git clone <repository-url>
cd expense-tracker

# Build the C++ application
make

# Run the CLI interface
./build/expense_tracker
```

### Running the Web Interface

```bash
# Create and activate virtual environment
python3 -m venv venv
source venv/bin/activate  # Windows: venv\Scripts\activate

# Install dependencies
pip install -r requirements.txt

# Start the Flask development server
python web/app.py

# Access the web interface
# Navigate to http://localhost:5000
```

### Docker Deployment

For containerized deployment with full orchestration:

```bash
# Build and run both services
docker-compose up --build

# Access CLI container
docker-compose exec cli ./expense_tracker

# Access web interface at http://localhost:5001
```

## Build Configuration

The project uses a sophisticated Makefile with multiple targets:

```bash
make all      # Default build target
make clean    # Remove build artifacts
make run      # Build and execute
make debug    # Debug build with symbols
make arch-info # Display system information
```

### Compiler Settings
- Standard: C++17
- Optimization: O2 level
- Warnings: Wall, Wextra enabled
- Include path: Automatic header resolution

## API Reference

### Core Classes

#### Expense Class
```cpp
class Expense {
public:
    Expense(double amount, const std::string& category, 
            const std::string& date, const std::string& note);
    
    // Accessors
    double getAmount() const;
    std::string getCategory() const;
    std::string getDate() const;
    std::string getNote() const;
    
    // Serialization
    std::string toCSV() const;
    static Expense fromCSV(const std::string& line);
};
```

#### ExpenseManager Class
```cpp
class ExpenseManager {
public:
    void addExpense(const Expense& expense);
    void editExpense(size_t index, const Expense& updated);
    void deleteExpense(size_t index);
    void showAllExpenses() const;
    double getTotalSpent() const;
    void searchExpenses(const std::string& query) const;
};
```

### Flask Routes

| Route | Method | Description |
|-------|--------|-------------|
| `/` | GET | Main dashboard with expense list |
| `/add` | POST | Add new expense |
| `/edit/<id>` | GET/POST | Edit existing expense |
| `/delete/<id>` | POST | Delete expense by ID |

## Configuration Options

### Environment Variables
- `FLASK_ENV`: Flask environment mode
- `PYTHONUNBUFFERED`: Python output buffering

### Data Persistence
- CSV format for cross-platform compatibility
- Automatic file creation on first run
- Configurable data directory location

## Security Considerations

### Password Management
- SHA-256 cryptographic hashing
- Secure input masking during password entry
- File-based hash storage with restricted permissions
- No plaintext password storage

### Data Protection
- Local file system storage (no external dependencies)
- Input validation and sanitization
- Protection against CSV injection attacks

## Development Guidelines

### Code Standards
- C++17 standard compliance
- RAII principle adherence
- Exception safety guarantees
- Memory leak prevention
- Consistent naming conventions

### Testing Approach
- Unit testing for core business logic
- Integration testing for file operations
- Cross-platform compatibility validation
- Memory usage profiling

## Deployment Options

### Local Development
Ideal for personal use with immediate file system access and native performance.

### Docker Container
Provides environment isolation and consistent deployment across different systems.

### Production Considerations
- Reverse proxy configuration for web interface
- File system permissions and security
- Backup and recovery procedures
- Monitoring and logging integration

## Troubleshooting

### Common Build Issues
- Ensure GCC 7.0+ with C++17 support
- Verify include path configuration
- Check file system permissions for data directory

### Runtime Problems
- Validate CSV file format integrity
- Confirm password file accessibility
- Check Flask port availability

### Performance Optimization
- Large dataset handling recommendations
- Memory usage optimization strategies
- File I/O performance tuning

## Roadmap

### Planned Enhancements
- RESTful API development for third-party integrations
- Advanced analytics with graphical reporting
- Multi-user support with role-based access control
- Database backend migration options
- Mobile application development
- Import/export functionality for various formats
- Automated backup scheduling
- Budget planning and forecasting tools

### Technical Improvements
- Unit test suite implementation
- Continuous integration pipeline
- Performance benchmarking suite
- Code coverage analysis
- Static analysis integration

## Contributing

This project follows standard C++ development practices and Flask conventions. Contributions should maintain the existing architecture patterns and coding standards.

### Development Setup
1. Fork the repository
2. Create feature branch
3. Implement changes with appropriate tests
4. Ensure build passes on all targets
5. Submit pull request with detailed description

## License

This project is released under the MIT License, providing maximum flexibility for personal and commercial use while maintaining attribution requirements.

## Author

Developed and maintained by BitGladiator. This project represents a practical implementation of modern C++ development practices combined with web application design principles.

---

For technical support, feature requests, or bug reports, please use the project's issue tracking system or contact the maintainer directly.
