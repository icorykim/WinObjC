//******************************************************************************
//
// Copyright (c) 2015 Microsoft Corporation. All rights reserved.
//
// This code is licensed under the MIT License (MIT).
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//
//******************************************************************************

#import "MenuTableViewController.h"

static NSString* controllerKeyName = @"ViewController";
static NSString* viewTitleKeyName = @"ViewName";

@interface MenuTableViewController ()

@end

@implementation MenuTableViewController

- (id)init {
    self = [super init];

    [self setTitle:@"WOCCatalog"];

    self.menuItems = [[NSMutableArray alloc] init];

    return self;
}

- (void)addMenuItemViewControllerClass:(Class)controllerClass andTitle:(NSString*)title {
    [self.menuItems addObject:[NSDictionary dictionaryWithObjectsAndKeys:title, viewTitleKeyName, controllerClass, controllerKeyName, nil]];
}
- (void)viewDidLoad {
    [super viewDidLoad];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

- (NSInteger)tableView:(UITableView*)tableView numberOfRowsInSection:(NSInteger)section {
    return [self.menuItems count];
}

- (UITableViewCell*)tableView:(UITableView*)tableView cellForRowAtIndexPath:(NSIndexPath*)indexPath {
    UITableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:@"MenuCell"];
    if (nil == cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"MenuCell"];
    }

    cell.textLabel.text = [[self.menuItems objectAtIndex:indexPath.row] objectForKey:viewTitleKeyName];
    cell.accessibilityIdentifier = cell.textLabel.text;

    return cell;
}

- (void)tableView:(UITableView*)tableView didSelectRowAtIndexPath:(NSIndexPath*)indexPath {
    Class viewControllerClass = [[self.menuItems objectAtIndex:indexPath.row] objectForKey:controllerKeyName];
    UIViewController* viewController = [[viewControllerClass alloc] init];
    [[self navigationController] pushViewController:viewController animated:YES];
}

@end
