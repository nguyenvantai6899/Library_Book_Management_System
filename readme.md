# Hướng Dẫn Sử Dụng Hệ Thống Quản Lý Thư Viện

## Giới Thiệu

Hệ thống Quản Lý Thư Viện (LMS) được thiết kế để quản lý sách và người dùng trong thư viện. Người dùng có thể thêm sách, đăng ký người dùng mới, mượn và trả sách, và tạo báo cáo về việc sử dụng sách. Tài liệu này cung cấp hướng dẫn sử dụng hệ thống.

## Tổng Quan Hệ Thống

Hệ thống bao gồm ba lớp chính:

- **Book (Sách)**: Đại diện cho một cuốn sách trong thư viện.
- **User (Người dùng)**: Đại diện cho một người dùng của thư viện.
- **LibrarySystem (Hệ thống Thư viện)**: Quản lý bộ sưu tập sách và người dùng, và cung cấp các chức năng để tương tác với chúng.

## Tính Năng

- Thêm Sách
- Thêm Người Dùng
- Mượn Sách
- Trả Sách
- Tìm Kiếm Sách
- Liệt Kê Tất Cả Các Sách
- Liệt Kê Tất Cả Người Dùng
- Báo Cáo Sách Được Mượn Nhiều Nhất
- Thoát

## Hướng Dẫn Sử Dụng

### 1. Tìm Kiếm Sách

**Mục Đích**: Tìm sách theo tiêu đề, tác giả hoặc thể loại.

**Các Bước**:

1. Chọn tùy chọn 1 từ menu.
2. Nhập từ khóa tìm kiếm (ví dụ: tên tác giả, tiêu đề sách, hoặc thể loại).
3. Hệ thống sẽ hiển thị các sách phù hợp với từ khóa tìm kiếm.

### 2. Liệt Kê Tất Cả Các Sách

**Mục Đích**: Hiển thị tất cả các sách có trong thư viện.

**Các Bước**:

1. Chọn tùy chọn 2 từ menu.
2. Hệ thống sẽ liệt kê tất cả các sách cùng với thông tin chi tiết của chúng.

### 3. Mượn Sách

**Mục Đích**: Cho phép người dùng mượn sách từ thư viện.

**Các Bước**:

1. Chọn tùy chọn 3 từ menu.
2. Nhập ID của người dùng đang mượn sách.
3. Nhập ID của cuốn sách đang được mượn.
4. Hệ thống sẽ cập nhật trạng thái của sách và danh sách sách đã mượn của người dùng.

### 4. Trả Sách

**Mục Đích**: Cho phép người dùng trả sách cho thư viện.

**Các Bước**:

1. Chọn tùy chọn 4 từ menu.
2. Nhập ID của người dùng đang trả sách.
3. Nhập ID của cuốn sách đang được trả.
4. Hệ thống sẽ cập nhật trạng thái của sách và danh sách sách đã mượn của người dùng.

### 5. Liệt Kê Tất Cả Người Dùng

**Mục Đích**: Hiển thị tất cả các người dùng đã đăng ký trong thư viện.

**Các Bước**:

1. Chọn tùy chọn 5 từ menu.
2. Hệ thống sẽ liệt kê tất cả các người dùng cùng với thông tin chi tiết và sách họ đã mượn.

### 6. Thoát

**Mục Đích**: Thoát khỏi hệ thống.

**Các Bước**:

1. Chọn tùy chọn 6 từ menu.
2. Chương trình sẽ kết thúc.

## Khắc Phục Sự Cố

- **Lựa Chọn Không Hợp Lệ**: Nếu bạn nhập một số không có trong menu, hệ thống sẽ hiển thị thông báo lỗi. Vui lòng nhập một tùy chọn hợp lệ.
- **Người Dùng hoặc Sách Không Tìm Thấy**: Đảm bảo rằng ID người dùng và ID sách bạn cung cấp là chính xác và tồn tại trong hệ thống.

## Hạn Chế

Hệ thống hiện tại không hỗ trợ báo cáo sách đã mượn quá hạn. Các bản cập nhật trong tương lai có thể bao gồm tính năng này.

## Cải Tiến Tương Lai

- Triển khai báo cáo sách đã mượn quá hạn.
- Cải thiện giao diện người dùng để dễ sử dụng hơn.
- Thêm chức năng cập nhật và xóa sách và người dùng.
